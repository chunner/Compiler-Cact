#!/bin/bash
# filepath: /home/skyward/cact/run1.sh

TEST_DIR="test/testcases/performance"
RUNTIME_LIB="libcact/libcactio.a"

# 创建必要的目录
mkdir -p build/result

# 日志文件
LOG_FILE="build/output.txt"
> "$LOG_FILE"  # 清空日志文件

# 记录开始时间
echo "=== Test Started at $(date) ===" | tee -a "$LOG_FILE"

# 检查compiler是否存在
if [ ! -f "build/compiler" ]; then
    echo -e "❌ Error: build/compiler not found!" | tee -a "$LOG_FILE"
    echo "Please run 'cd build && make' first" | tee -a "$LOG_FILE"
    exit 1
fi

# 检查test目录是否存在
if [ ! -d "$TEST_DIR" ]; then
    echo -e "❌ Error: test directory not found!" | tee -a "$LOG_FILE"
    exit 1
fi

# 统计变量
TOTAL=0
SUCCESS=0
COMPILER_FAIL=0
LLC_FAIL=0
RUNTIME_FAIL=0
OUTPUT_MISMATCH=0

echo -e "Starting compilation and execution tests with input/output validation..." | tee -a "$LOG_FILE"
echo "" | tee -a "$LOG_FILE"

# 使用数组读取所有.cact文件
mapfile -t cact_files < <(find "$TEST_DIR" -name "*.cact" -type f | sort)

# 遍历所有.cact文件
for input_file in "${cact_files[@]}"; do
    # 获取文件基础名（不含路径和扩展名）
    base_path="${input_file%.*}"  # 移除.cact扩展名
    filename=$(basename "$base_path")
    
    # 定义相关文件路径
    input_data_file="${base_path}.in"
    expected_output_file="${base_path}.out"
    output_ll="build/result/${filename}.ll"
    output_s="build/result/${filename}.s"
    output_exe="build/result/${filename}"
    actual_output_file="build/result/${filename}.actual"
    tree_file="build/result/${filename}.tree"
    
    echo -e "[$TOTAL] Processing: $input_file" | tee -a "$LOG_FILE"
    TOTAL=$((TOTAL + 1))

    # 检查是否存在对应的.out文件
    if [ ! -f "$expected_output_file" ]; then
        echo "  ⚠️  Warning: Expected output file not found: $expected_output_file" | tee -a "$LOG_FILE"
        echo "  Skipping this test case..." | tee -a "$LOG_FILE"
        echo "" | tee -a "$LOG_FILE"
        continue
    fi
    
    # 步骤1: 编译到LLVM IR
    echo "  Step 1: Compiling to LLVM IR..." | tee -a "$LOG_FILE"
    if timeout 30s ./build/compiler "$input_file" "$output_ll" 2>> "$LOG_FILE" | tee -a "$tree_file"; then
        if [ -f "$output_ll" ] && [ -s "$output_ll" ]; then
            echo -e "  ✅ Compiler succeeded" | tee -a "$LOG_FILE"
            
            # 步骤2: 使用llc编译为汇编
            echo "  Step 2: Compiling with llc..." | tee -a "$LOG_FILE"
            if timeout 30s llc "$output_ll" -o "$output_s" 2>&1 | tee -a "$LOG_FILE"; then
                echo -e "  ✅ llc succeeded" | tee -a "$LOG_FILE"
                
                # 步骤3: 链接生成可执行文件
                echo "  Step 3: Linking with runtime library..." | tee -a "$LOG_FILE"
                
                # 构建链接命令
                if [ -n "$RUNTIME_LIB" ] && [ -f "$RUNTIME_LIB" ]; then
                    link_cmd="gcc $output_s $RUNTIME_LIB -o $output_exe"
                    echo "    Using runtime library: $RUNTIME_LIB" | tee -a "$LOG_FILE"
                else
                    link_cmd="gcc $output_s -o $output_exe"
                    echo "    No runtime library found" | tee -a "$LOG_FILE"
                fi
                
                if timeout 30s $link_cmd 2>&1 | tee -a "$LOG_FILE"; then
                    echo -e "  ✅ Linking succeeded" | tee -a "$LOG_FILE"
                    
                    # 步骤4: 执行程序并捕获输出
                    echo "  Step 4: Executing program..." | tee -a "$LOG_FILE"
                    
                    # 准备输入数据
                    if [ -f "$input_data_file" ]; then
                        echo "    Using input file: $input_data_file" | tee -a "$LOG_FILE"
                    else
                        echo "    No input file found, using empty input" | tee -a "$LOG_FILE"
                    fi
                    
                    # 执行程序并捕获输出和退出码
                    exe_exit_code=0
                    if [ -f "$input_data_file" ]; then
                        # 有输入文件
                        timeout 10s "$output_exe" < "$input_data_file" > "$actual_output_file" 2>&1
                        exe_exit_code=$?
                    else
                        # 无输入文件
                        timeout 10s "$output_exe" > "$actual_output_file" 2>&1
                        exe_exit_code=$?
                    fi
                    
                    # 检查是否超时（timeout的退出码是124）
                    if [ $exe_exit_code -eq 124 ]; then
                        echo "  ❌ Program execution timed out" | tee -a "$LOG_FILE"
                        RUNTIME_FAIL=$((RUNTIME_FAIL + 1))
                        echo "" | tee -a "$LOG_FILE"
                        continue
                    # elif [ $exe_exit_code -gt 128 ]; then
                    #     echo "  ❌ Program execution failed with signal" | tee -a "$LOG_FILE"
                    #     RUNTIME_FAIL=$((RUNTIME_FAIL + 1))
                    #     echo "" | tee -a "$LOG_FILE"
                    #     continue
                    fi
                    
                    echo "  Program exit code: $exe_exit_code" | tee -a "$LOG_FILE"
                    
                    # 检查输出文件是否有内容，如果有则在exit code前加换行
                    if [ -s "$actual_output_file" ]; then
                        # 文件非空，说明有print输出，加换行
                        #echo "" >> "$actual_output_file"
                        echo "$exe_exit_code" >> "$actual_output_file"
                    else
                        # 文件为空，说明没有print输出，直接添加exit code
                        echo "$exe_exit_code" >> "$actual_output_file"
                    fi
                    
                    # 步骤5: 比较输出
                    echo "  Step 5: Comparing output..." | tee -a "$LOG_FILE"
                    
                    # 读取期望输出和实际输出
                    expected_output=$(cat "$expected_output_file" 2>/dev/null || echo "")
                    actual_output=$(cat "$actual_output_file" 2>/dev/null || echo "")
                    
                    # 比较输出
                    if [ "$expected_output" = "$actual_output" ]; then
                        echo -e "  ✅ Output matches expected result!" | tee -a "$LOG_FILE"
                        SUCCESS=$((SUCCESS + 1))
                    else
                        echo -e "  ❌ Output mismatch!" | tee -a "$LOG_FILE"
                        echo "    Expected output:" | tee -a "$LOG_FILE"
                        echo "$expected_output" | sed 's/^/      /' | tee -a "$LOG_FILE"
                        echo "    Actual output:" | tee -a "$LOG_FILE"
                        echo "$actual_output" | sed 's/^/      /' | tee -a "$LOG_FILE"
                        OUTPUT_MISMATCH=$((OUTPUT_MISMATCH + 1))
                    fi
                    
                else
                    echo -e "  ❌ Linking failed" | tee -a "$LOG_FILE"
                    LLC_FAIL=$((LLC_FAIL + 1))
                fi
            else
                echo -e "  ❌ llc failed" | tee -a "$LOG_FILE"
                LLC_FAIL=$((LLC_FAIL + 1))
            fi
        else
            echo -e "  ❌ Compiler produced no output" | tee -a "$LOG_FILE"
            COMPILER_FAIL=$((COMPILER_FAIL + 1))
        fi
    else
        echo -e "  ❌ Compiler failed" | tee -a "$LOG_FILE"
        COMPILER_FAIL=$((COMPILER_FAIL + 1))
    fi
    
    echo "" | tee -a "$LOG_FILE"
done

# 输出统计信息
echo "=== Test Summary ===" | tee -a "$LOG_FILE"
echo "Total files processed: $TOTAL" | tee -a "$LOG_FILE"
echo -e "✅ Successful: $SUCCESS" | tee -a "$LOG_FILE"
echo -e "❌ Compiler failures: $COMPILER_FAIL" | tee -a "$LOG_FILE"
echo -e "❌ LLC failures: $LLC_FAIL" | tee -a "$LOG_FILE"
echo -e "❌ Runtime failures: $RUNTIME_FAIL" | tee -a "$LOG_FILE"
echo -e "❌ Output mismatches: $OUTPUT_MISMATCH" | tee -a "$LOG_FILE"

# 计算总失败数
TOTAL_FAIL=$((COMPILER_FAIL + LLC_FAIL + RUNTIME_FAIL + OUTPUT_MISMATCH))

if [ $SUCCESS -eq $TOTAL ] && [ $TOTAL_FAIL -eq 0 ]; then
    echo -e "🎉 All tests passed!" | tee -a "$LOG_FILE"
    exit 0
else
    echo -e "⚠️  Some tests failed. Check the log for details." | tee -a "$LOG_FILE"
    echo -e "Success rate: $SUCCESS/$TOTAL ($(( SUCCESS * 100 / TOTAL ))%)" | tee -a "$LOG_FILE"
    exit 1
fi

echo "=== Test Completed at $(date) ===" | tee -a "$LOG_FILE"
echo -e "Full log saved to: $LOG_FILE"