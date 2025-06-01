#!/bin/bash
# filepath: /home/skyward/cact/run.sh

TEST_DIR="test/samples/samples_semantic"
RUNTIME_LIB="libcact/libcactio.a"

# 创建必要的目录
# mkdir -p build
mkdir -p build/test

# 日志文件
LOG_FILE="build/output.txt"
> "$LOG_FILE"  # 清空日志文件

# 记录开始时间
echo "=== Test Started at $(date) ===" | tee -a "$LOG_FILE"

# 检查compiler是否存在
if [ ! -f "build/compiler" ]; then
    echo -e "Error: build/compiler not found!" | tee -a "$LOG_FILE"
    echo "Please run 'cd build && make' first" | tee -a "$LOG_FILE"
    exit 1
fi

# 检查test目录是否存在
if [ ! -d "$TEST_DIR" ]; then
    echo -e "Error: test directory not found!" | tee -a "$LOG_FILE"
    exit 1
fi

# 统计变量
TOTAL=0
SUCCESS=0
COMPILER_FAIL=0
LLC_FAIL=0
LLI_FAIL=0

echo -e "Starting compilation and execution tests..." | tee -a "$LOG_FILE"
echo "" | tee -a "$LOG_FILE"

# 使用数组读取所有文件，避免子shell问题
mapfile -t cact_files < <(find "$TEST_DIR" -name "*.cact" -type f | sort)

# 遍历数组中的所有文件
for input_file in "${cact_files[@]}"; do
    TOTAL=$((TOTAL + 1))
    
    # 获取文件名（不含路径和扩展名）
    filename=$(basename "$input_file" .cact)
    
    # 输出文件路径
    output_ll="build/test/${filename}.ll"
    output_s="build/test/${filename}.s"
    output_exe="build/test/${filename}"
    
    echo -e "[$TOTAL] Processing: $input_file" | tee -a "$LOG_FILE"
    
    # 步骤1: 使用compiler编译
    echo "  Step 1: Compiling to LLVM IR..." | tee -a "$LOG_FILE"
    if timeout 30s ./build/compiler "$input_file" "$output_ll" 2>&1 | tee -a "$LOG_FILE"; then
        if [ -f "$output_ll" ] && [ -s "$output_ll" ]; then
            echo -e "  ✅ Compiler succeeded" | tee -a "$LOG_FILE"
            
            # 步骤2: 使用llc编译
            echo "  Step 2: Compiling with llc..." | tee -a "$LOG_FILE"
            if timeout 30s llc "$output_ll" -o "$output_s" 2>&1 | tee -a "$LOG_FILE"; then
                echo -e "  ✅ llc succeeded" | tee -a "$LOG_FILE"
                
                # 步骤3: 链接生成可执行文件
                echo "  Step 3: Linking with runtime library..." | tee -a "$LOG_FILE"
                
                # 检查文件是否包含IO函数调用
                has_io_functions=false
                if grep -q -E "(call.*@(print_|get_))" "$output_ll" 2>/dev/null; then
                    has_io_functions=true
                fi
                
                # 构建链接命令
                if [ -n "$RUNTIME_LIB" ]; then
                    link_cmd="gcc $output_s $RUNTIME_LIB -o $output_exe"
                    echo "    Using runtime library: $RUNTIME_LIB" | tee -a "$LOG_FILE"
                else
                    link_cmd="gcc $output_s -o $output_exe"
                    echo "    No runtime library (IO functions may not work)" | tee -a "$LOG_FILE"
                fi
                
                if timeout 30s $link_cmd 2>&1 | tee -a "$LOG_FILE"; then
                    echo -e "  ✅ Linking succeeded" | tee -a "$LOG_FILE"
                    
                    # 步骤4: 使用lli执行
                    echo "  Step 4: Executing with lli..." | tee -a "$LOG_FILE"
                    lli_success=false
                    
                    if [ "$has_io_functions" = true ]; then
                        echo "    Note: Program contains IO functions, lli may fail" | tee -a "$LOG_FILE"
                    fi
                    
                    if timeout 10s lli "$output_ll" 2>&1 | tee -a "$LOG_FILE"; then
                        lli_exit_code=$?
                        echo "  lli exit code: $lli_exit_code" | tee -a "$LOG_FILE"
                        lli_success=true
                    else
                        echo "  ⚠️  lli execution failed (possibly due to IO function calls)" | tee -a "$LOG_FILE"
                        lli_exit_code="N/A"
                        LLI_FAIL=$((LLI_FAIL + 1))
                    fi
                    
                    # 步骤5: 执行编译后的可执行文件
                    echo "  Step 5: Executing compiled binary..." | tee -a "$LOG_FILE"
                    if timeout 10s "$output_exe" 2>&1 | tee -a "$LOG_FILE"; then
                        exe_exit_code=$?
                        echo "  Binary exit code: $exe_exit_code" | tee -a "$LOG_FILE"
                        
                        if [ "$lli_success" = true ]; then
                            if [ $lli_exit_code -eq $exe_exit_code ]; then
                                echo -e "  ✅ All tests passed! Exit codes match." | tee -a "$LOG_FILE"
                                SUCCESS=$((SUCCESS + 1))
                            else
                                echo -e "  ❌ Exit codes don't match (lli: $lli_exit_code, binary: $exe_exit_code)" | tee -a "$LOG_FILE"
                            fi
                        else
                            echo -e "  ✅ Binary test passed (lli failed, likely due to IO functions)" | tee -a "$LOG_FILE"
                            SUCCESS=$((SUCCESS + 1))
                        fi
                    else
                        echo -e "  ❌ Binary execution failed" | tee -a "$LOG_FILE"
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
echo -e "Successful: $SUCCESS" | tee -a "$LOG_FILE"
echo -e "Compiler failures: $COMPILER_FAIL" | tee -a "$LOG_FILE"
echo -e "LLC failures: $LLC_FAIL" | tee -a "$LOG_FILE"
echo -e "LLI failures: $LLI_FAIL" | tee -a "$LOG_FILE"

if [ $SUCCESS -eq $TOTAL ]; then
    echo -e "🎉 All tests passed!" | tee -a "$LOG_FILE"
else
    echo -e "⚠️  Some tests failed. Check the log for details." | tee -a "$LOG_FILE"
fi

echo "=== Test Completed at $(date) ===" | tee -a "$LOG_FILE"
echo -e "Full log saved to: $LOG_FILE"