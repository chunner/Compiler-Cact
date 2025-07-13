#include "RiscvGenerator.h"
#include <regex>


RiscvGenerator::RiscvGenerator(const LLVMModule &module) :_module(module) {
};

void RiscvGenerator::generate(std::ostream &out) {
    // 1. 生成 .data 段 (全局变量)
    _dataSection << ".data\n";
    for (const auto &entry : _module.entries) {
        if (std::holds_alternative<LLVMGlobalVar>(entry)) {
            generateGlobalVar(std::get<LLVMGlobalVar>(entry));
        }
    }

    // 2. 生成 .text 段 (函数代码)
    _textSection << ".text\n";
    for (const auto &entry : _module.entries) {
        if (std::holds_alternative<LLVMFunction>(entry)) {
            const auto &func = std::get<LLVMFunction>(entry);
            // 对于内置函数，我们只需要一个声明
            if (func.basicblocks.empty()) {
                _textSection << ".globl " << func.name << "\n";
            } else {
                generateFunction(func);
            }
        }
    }

    // 3. 组合并输出
    out << _dataSection.str() << "\n" << _textSection.str();
}


void RiscvGenerator::generateGlobalVar(const LLVMGlobalVar &var) {
    // 示例1: @g = global i32 10
    // 转换:
    // .globl g
    // g:
    //   .word 10

    // 示例2: @a = constant [5 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4]
    // 转换:
    // .globl a
    // a:
    //   .word 0
    //   .word 1
    //   .word 2
    //   .word 3
    //   .word 4

    // 示例3: declare void @print_int(i32)
    // 转换:
    // .globl print_int

    // 对于函数声明, 直接跳过
    if (var.type.isFunction) {
        return;
    }
    std::string varName = var.name.substr(1); // 去掉前缀 '@'
    _dataSection << ".globl " << varName << "\n";
    if (var.type.baseType == BaseType::DOUBLE) {
        // double类型需要8字节对齐
        _dataSection << ".align 3\n"; // 2^3 = 8 bytes
    } else if (var.type.baseType == BaseType::I32 || var.type.baseType == BaseType::FLOAT || var.type.baseType == BaseType::I8) {
        // i32, float, i8类型需要4字节对齐
        _dataSection << ".align 2\n"; // 2^2 = 4 bytes
    }
    _dataSection << varName << ":\n";

    if (var.type.isArray()) {
        // 情况1: 数组，且有明确的初始化列表 (形如 "[i32 1, i32 2, ...]")
        if (!var.initValue.empty()) {
            if (var.type.baseType == BaseType::I32) {
                // 如果是 i32 数组，使用 .word 指令
                std::string value_str = var.initValue;
                std::regex re(R"(i32\s+(-?\d+))");
                auto words_begin = std::sregex_iterator(value_str.begin(), value_str.end(), re);
                auto words_end = std::sregex_iterator();
                for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
                    std::smatch match = *i;
                    std::string value = match[1].str(); // 提取捕获的数值
                    _dataSection << "  .word " << value << "\n";
                }
            } else if (var.type.baseType == BaseType::FLOAT) {
                // 如果是 float 数组，使用 .float 指令
                std::string value_str = var.initValue;
                std::regex re(R"(float\s+([-+]?\d*\.?\d+([eE][-+]?\d+)?))");
                auto words_begin = std::sregex_iterator(value_str.begin(), value_str.end(), re);
                auto words_end = std::sregex_iterator();
                for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
                    std::smatch match = *i;
                    std::string value = match[1].str(); // 提取捕获的数值
                    _dataSection << "  .float " << value << "\n";
                }
            } else if (var.type.baseType == BaseType::I8) {
                // 如果是 i8 数组，使用 .byte 指令
                std::string value_str = var.initValue;
                std::regex re(R"(i8\s+(-?\d+))");
                auto words_begin = std::sregex_iterator(value_str.begin(), value_str.end(), re);
                auto words_end = std::sregex_iterator();
                for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
                    std::smatch match = *i;
                    std::string value = match[1].str(); // 提取捕获的数值
                    _dataSection << "  .byte " << value << "\n";
                }

            }
        }
        // 情况2: 数组，但是未初始化或使用 zeroinitializer
        else {
            // .zero 指令会分配空间并用0填充
            // getArraySize() 返回的是字节数
            _dataSection << "  .zero " << var.type.getArraySize() << "\n";
        }
    }
    // 情况3: 非数组的简单全局变量
    else {
        // 如果没有初始值，默认为0
        std::string initVal = var.initValue.empty() ? "0" : var.initValue;
        if (var.type.baseType == BaseType::DOUBLE) {
            // double类型使用 .double 指令
            _dataSection << "  .double " << initVal << "\n";
        } else if (var.type.baseType == BaseType::I32) {
            // i32类型使用 .word 指令
            _dataSection << "  .word " << initVal << "\n";
        } else if (var.type.baseType == BaseType::FLOAT) {
            // float类型使用 .float 指令
            _dataSection << "  .float " << initVal << "\n";
        } else if (var.type.baseType == BaseType::I8 || var.type.baseType == BaseType::I1) {
            // i8类型使用 .byte 指令
            _dataSection << "  .byte " << initVal << "\n";
        }
    }
    _dataSection << "\n"; // 在每个全局变量定义后加一个空行，更美观

    // 注册全局变量
    _global_var.push_back(GlobalVar(varName));
}

void RiscvGenerator::generateFunction(const LLVMFunction &func) {
    _textSection << ".globl " << func.name << "\n";
    _textSection << func.name << ":\n";

    _currentFrame = RiscvFrame(); // 新建栈帧
    _regMap.clear();             // 清空寄存器映射
    _usedRegs = std::vector<bool>(7, false);
    tempRegIndex = 0; // 重置临时寄存器索引
    _currentFunction = func;

    // 遍历所有指令，计算栈帧大小
    _currentFrame.analyzeFunction(func);
    int frameSize = _currentFrame.getTotalFrameSize();
    // for (const auto &block : func.basicblocks) {
    //     for (const auto &inst : block->llvm_ins) {
    //         if (inst.type == LLVM_INS_T::ALLOCA) {
    //             frameSize += std::stoi(inst.operands[1]);
    //         }
    //     }
    // }


    // --- 函数序言 (Prologue) ---
    _textSection << "  # Function Prologue\n";
    _textSection << "  addi sp, sp, -" << frameSize << "\n";
    _textSection << "  sd ra, " << _currentFrame.RA_OFFSET << "(sp)\n";
    _textSection << "  sd s0, " << _currentFrame.FP_OFFSET << "(sp)\n";
    _textSection << "  addi s0, sp, " << frameSize << "\n";

    // --- 函数体 ---
    for (const auto &block : func.basicblocks) {
        generateBasicBlock(*block);
    }

    // --- 函数尾声 (Epilogue) ---
    _textSection << ".L" << func.name << "_exit:\n"; // 创建一个统一的退出点
    _textSection << "  # Function Epilogue\n";
    _textSection << "  ld ra, " << _currentFrame.RA_OFFSET << "(sp)\n";
    _textSection << "  ld s0, " << _currentFrame.FP_OFFSET << "(sp)\n";
    _textSection << "  addi sp, sp, " << frameSize << "\n";
    _textSection << "  ret\n"; // 返回指令
}

void RiscvGenerator::generateBasicBlock(const LLVMBasicBlock &block) {
    _textSection << block.label << ":\n";
    for (const auto &inst : block.llvm_ins) {
        switch (inst.type) {
        case LLVM_INS_T::ALLOCA:
            generateAlloca(inst);
            break;
        case LLVM_INS_T::LOAD:
            generateLoad(inst);
            break;
        case LLVM_INS_T::STORE:
            generateStore(inst);
            break;
        case LLVM_INS_T::ADD:
        case LLVM_INS_T::SUB:
        case LLVM_INS_T::MUL:
        case LLVM_INS_T::DIV:
            generateArithmetic(inst);
            break;
        case LLVM_INS_T::BR:
            generateBranch(inst);
            break;
        case LLVM_INS_T::RET:
            generateRet(inst);
            break;
        case LLVM_INS_T::GEP:
            generateGEP(inst);
            break;
        default:
            // 其他指令类型暂不处理
            break;
        }
    }
}

void RiscvGenerator::generateAlloca(const LLVM_INS &inst) {
    // 示例: %a = alloca i32
    // 转换:

    std::string varName = inst.result.substr(1); // 去掉前缀 '%'
    int size = std::stoi(inst.operands[1]); // 第二个操作数是分配的字节数

    _currentFrame.addLocal(varName, size);
    int offset = _currentFrame.getOffset(varName);
}

void RiscvGenerator::generateLoad(const LLVM_INS &inst) {
    // 示例: %a = load i32, i32* %b
    // 转换:
    //   lw t0, 8(sp)
    //   sw t0, 4(sp)

    std::string dest = inst.result.substr(1); // 目标位置
    std::string srcPtr = inst.operands[1]; // 源指针
    bool global_src = srcPtr[0] == '@'; // 检查是否是全局变量
    if (srcPtr[0] == '%' || srcPtr[0] == '@') {
        srcPtr = srcPtr.substr(1); // 去掉前缀 '%'
    }

    _textSection << "  # Load " << dest << " from " << srcPtr << "\n";
    std::string tempReg;
    if (std::regex_match(srcPtr, std::regex(R"(\d+)"))) {
        // 如果是立即数，直接将其加载到临时寄存器
        tempReg = getTempReg();
        _textSection << "  li " << tempReg << ", " << srcPtr << "\n"; // 将立即数加载到寄存器
    } else if (_regMap.find(srcPtr) != _regMap.end()) {
        tempReg = _regMap[srcPtr]; // 如果在寄存器中
    }else if (global_src) {
        // 如果是全局变量，直接加载到临时寄存器
        tempReg = getTempReg();
        _textSection << "  lw " << tempReg << ", " << srcPtr << "\n"; // 从全局变量加载值
    } else {
        tempReg = getTempReg(); // 否则分配一个临时寄存器
        int offset = _currentFrame.getOffset(srcPtr);
        _textSection << "  lw " << tempReg << ", " << offset << "(sp)\n"; // 从栈加载值
    }

    // 将加载的值存储到目标位置
    _currentFrame.addLocal(dest, 4);
    int destOffset = _currentFrame.getOffset(dest);
    _textSection << "  sw " << tempReg << ", " << destOffset << "(sp)\n"; // 将值存储到栈上

    // 更新寄存器映射
    _regMap[dest] = tempReg;
}

void RiscvGenerator::generateStore(const LLVM_INS &inst) {
    // 示例: store i32 %a, i32* %b
    // 转换:
    //   lw t0, a
    //   sw t0, 0(b)

    std::string src = inst.operands[0]; // 源位置
    std::string destPtr = inst.operands[1]; // 目标指针
    if (src[0] == '%' || src[0] == '@') {
        src = src.substr(1); // 去掉前缀 '%'
    }
    if (destPtr[0] == '%' || destPtr[0] == '@') {
        destPtr = destPtr.substr(1); // 去掉前缀 '%'
    }

    _textSection << "  # Store " << src << " to " << destPtr << "\n";
    // 将源操作数加载到临时寄存器
    std::string srcReg;
    if (std::regex_match(src, std::regex(R"(\d+)"))) {
        // 如果是立即数，直接将其加载到临时寄存器
        srcReg = getTempReg();
        _textSection << "  li " << srcReg << ", " << src << "\n"; // 将立即数加载到寄存器
    } else if (_regMap.find(src) != _regMap.end()) {
        srcReg = _regMap[src]; // 如果在寄存器中
    } else {
        srcReg = getTempReg(); // 否则分配一个临时寄存器
        _textSection << "  lw " << srcReg << ", " << src << "\n"; // 从栈加载值
    }

    // 存储到目标指针
    int offset = _currentFrame.getOffset(destPtr);
    _textSection << "  sw " << srcReg << ", " << offset << "(sp)\n";

    // 更新寄存器映射
    _regMap[destPtr] = srcReg;
}

void RiscvGenerator::generateArithmetic(const LLVM_INS &inst) {
    // 示例: %c = add i32 %a, %b
    // 转换:
    //   lw t0, a
    //   lw t1, b
    //   add t2, t0, t1
    //   sw t2, c

    std::string dest = inst.result; // 目标位置
    if (dest[0] == '%' || dest[0] == '@') {
        dest = dest.substr(1); // 去掉前缀 '%'
    }
    std::string op1 = inst.operands[0]; // 第一个操作数
    bool global_op1 = op1[0] == '@'; // 检查是否是全局变量
    if (op1[0] == '%' || op1[0] == '@') {
        op1 = op1.substr(1); // 去掉前缀 '%'
    }
    std::string op2 = inst.operands[1]; // 第二个操作数
    bool global_op2 = op2[0] == '@'; // 检查是否是全局变量
    if (op2[0] == '%' || op2[0] == '@') {
        op2 = op2.substr(1); // 去掉前缀 '%'
    }

    std::string tempReg1;
    std::string tempReg2;
    std::string resultReg;

    _textSection << "  # Arithmetic " << " " << dest << " = " << op1 << " op " << op2 << "\n";

    // 加载第一个操作数
    if (_regMap.find(op1) != _regMap.end()) {
        tempReg1 = _regMap[op1]; // 如果在寄存器中
    } else if (global_op1) {
        // 如果是全局变量，直接加载到临时寄存器
        tempReg1 = getTempReg();
        _textSection << "  lw " << tempReg1 << ", " << op1 << "\n"; // 从全局变量加载值
    } else if (std::regex_match(op1, std::regex(R"(\d+)"))) {
        // 如果是立即数，直接将其加载到临时寄存器
        tempReg1 = getTempReg();
        _textSection << "  li " << tempReg1 << ", " << op1 << "\n"; // 将立即数加载到寄存器
    } else {
        tempReg1 = getTempReg(); // 否则分配一个临时寄存器
        int offset = _currentFrame.getOffset(op1);
        _textSection << "  lw " << tempReg1 << ", " << offset << "(sp)\n"; // 从栈加载值
    }

    // 加载第二个操作数
    if (_regMap.find(op2) != _regMap.end()) {
        tempReg2 = _regMap[op2]; // 如果在寄存器中
    } else if (global_op2) {
        // 如果是全局变量，直接加载到临时寄存器
        tempReg2 = getTempReg();
        _textSection << "  lw " << tempReg2 << ", " << op2 << "\n"; // 从全局变量加载值
    } else if (std::regex_match(op2, std::regex(R"(\d+)"))) {
        // 如果是立即数，直接将其加载到临时寄存器
        tempReg2 = getTempReg();
        _textSection << "  li " << tempReg2 << ", " << op2 << "\n"; // 将立即数加载到寄存器
    } else {
        tempReg2 = getTempReg(); // 否则分配一个临时寄存器
        int offset = _currentFrame.getOffset(op2);
        _textSection << "  lw " << tempReg2 << ", " << offset << "(sp)\n"; // 从栈加载值
    }

    // 执行算术运算
    resultReg = getTempReg(); // 分配一个新的临时寄存器来存储结果
    switch (inst.type) {
    case LLVM_INS_T::ADD:
        _textSection << "  add " << resultReg << ", " << tempReg1 << ", " << tempReg2 << "\n";
        break;
    case LLVM_INS_T::SUB:
        _textSection << "  sub " << resultReg << ", " << tempReg1 << ", " << tempReg2 << "\n";
        break;
    case LLVM_INS_T::MUL:
        _textSection << "  mul " << resultReg << ", " << tempReg1 << ", " << tempReg2 << "\n";
        break;
    case LLVM_INS_T::DIV:
        _textSection << "  div " << resultReg << ", " << tempReg1 << ", " << tempReg2 << "\n";
        break;
    default:
        throw std::runtime_error("Unsupported arithmetic operation: " + std::to_string(static_cast<int>(inst.type)));
    }

    //更新寄存器映射
    _regMap[dest] = resultReg; 

    // 将结果存储到栈上
    _currentFrame.addLocal(dest, 4); // 假设每个元素是 i32，分配 4 字节
    int destOffset = _currentFrame.getOffset(dest);
    _textSection << "  sw " << resultReg << ", " << destOffset << "(sp)\n"; // 将结果存储到栈上
}


void RiscvGenerator::generateBranch(const LLVM_INS &inst) {
    // 示例: br label %label
    // 转换:
    //   j label

    // 示例: br i1 %cond, label %true_label, label %false_label
    // 转换:
    //   beqz cond, false_label

    if (inst.operands.size() == 1) {
        // 无条件跳转
        std::string targetLabel = inst.operands[0];
        _textSection << "  # Unconditional branch to " << targetLabel << "\n";
        _textSection << "  j " << targetLabel << "\n";
    } else if (inst.operands.size() == 3) {
        // 有条件跳转
        std::string cond = inst.operands[0]; // 条件
        std::string trueLabel = inst.operands[1]; // 真分支标签
        std::string falseLabel = inst.operands[2]; // 假分支标签

        if (_regMap.find(cond) != _regMap.end()) {
            // 如果条件在寄存器中
            _textSection << "  # Conditional branch on " << cond << "\n";
            _textSection << "  beqz " << _regMap[cond] << ", " << falseLabel << "\n"; // 如果条件为0，跳转到假分支
            _textSection << "  j " << trueLabel << "\n"; // 否则跳转到真分支
        } else {
            throw std::runtime_error("Condition not found in register map: " + cond);
        }
    } else {
        throw std::runtime_error("Invalid branch instruction format");
    }
}


void RiscvGenerator::generateRet(const LLVM_INS &inst) {
    // 示例: ret i32 %a
    // 转换:
    //   lw a0, a
    //   j .Lexit
    if (inst.operands.empty()) {
        // 无返回值的函数
        _textSection << "  # Return from function\n";
        _textSection << "  j .L" << _currentFunction.name << "_exit\n";
    } else {
        // 有返回值的函数
        std::string retVal = inst.operands[0]; // 返回值
        if (retVal[0] == '%' || retVal[0] == '@') {
            retVal = retVal.substr(1); // 去掉前缀 '%'
        }
        if (std::regex_match(retVal, std::regex(R"(\d+)"))) {
            // 如果是立即数，直接将其加载到 a0 寄存器
            _textSection << "  # Return immediate value " << retVal << " from function\n";
            _textSection << "  li a0, " << retVal << "\n"; // 将立即数加载到 a0 寄存器
        } else if (_regMap.find(retVal) != _regMap.end()) {
            // 如果返回值在寄存器中
            _textSection << "  # Return " << retVal << " from function\n";
            _textSection << "  mv a0, " << _regMap[retVal] << "\n"; // 将返回值移动到 a0 寄存器
        } else {
            // 如果返回值在栈上
            _textSection << "  # Load return value " << retVal << " from stack\n";
            int offset = _currentFrame.getOffset(retVal);
            _textSection << "  lw a0, " << offset << "(sp)\n"; // 从栈加载返回值到 a0 寄存器
        }
        _textSection << "  j .L" << _currentFunction.name << "_exit\n"; // 跳转到统一的退出点
    }
}

void RiscvGenerator::generateGEP(const LLVM_INS &instr) {
    // 示例: %ptr13 = getelementptr inbounds [4 x [2 x i32]], [4 x [2 x i32]]* %e9, i32 0, i32 0, i32 0
    // 转换:
    //   lw t0, 8(sp)  // 假设 %e9 在栈上
    //   li t1, 0
    //   li t2, 0
    //   li t3, 0
    //   slli t1, t1, 2  // 假设每个元素是 i32，乘以 4
    //   slli t2, t2, 3  // 假设每个元素是 [2 x i32]，乘以 8
    //   add t0, t0, t1  // 加上第一个索引的偏移
    //   add t0, t0, t2  // 加上第二个索引的偏移
    std::string dest = instr.result;
    if (dest[0] == '%' || dest[0] == '@') {
        dest = dest.substr(1); // 去掉前缀 '%'
    }
    // instr.operands[0] 是整条指令, 使用正则匹配提取源指针
    std::regex re(R"(\* ([^,]+))");
    std::smatch match;
    std::regex_search(instr.operands[0], match, re);
    std::string srcPtr = match[1]; // 提取源指针
    if (srcPtr[0] == '%' || srcPtr[0] == '@') {
        srcPtr = srcPtr.substr(1); // 去掉前缀 '%'
    }
    _textSection << "  # GEP " << dest << " from " << srcPtr << "\n";
    std::string srcReg;
    if (_regMap.find(srcPtr) != _regMap.end()) {
        srcReg = _regMap[srcPtr]; // 如果在寄存器中
    } else {
        srcReg = getTempReg(); // 否则分配一个临时寄存器
        int offset = _currentFrame.getOffset(srcPtr);
        _textSection << "  lw " << srcReg << ", " << offset << "(sp)\n"; // 从栈加载值
    }
    std::vector<int> indices;
    std::vector<int> indexlen;
    std::regex reIndex (R"(i32\s+(\d+))");
    std::string instruction = instr.operands[0];
    while(std::regex_search(instruction, match, reIndex)) {
        indices.push_back(std::stoi(match[1].str()));
        instruction = match.suffix().str(); // 更新指令字符串
    }
    std::regex reIndexLen (R"((\d+)\s+x)");
    instruction = instr.operands[0];
    while(std::regex_search(instruction, match, reIndexLen)) {
        indexlen.push_back(std::stoi(match[1].str()));
        instruction = match.suffix().str(); // 更新指令字符串
    }
    // 计算偏移量
    int offset = 0;
    for (size_t i = 0; i < indices.size(); ++i) {
        int index = indices[i];
        int len = indexlen[i];
        if (i == 0) {
            // 第一维的偏移量
            offset += index * 4; // 假设每个元素是 i32，乘以 4
        } else {
            // 其他维度的偏移量
            offset += index * (len * 4); // 假设每个元素是 i32，乘以 4
        }
    }   

    // 将偏移量加载到临时寄存器
    std::string offsetReg = getTempReg();
    _textSection << "  li " << offsetReg << ", " << offset << "\n"; // 将偏移量加载到寄存器
    // 计算最终地址
    std::string destReg = getTempReg(); // 分配一个新的临时寄存器来存储结果地址
    _textSection << "  add " << destReg << ", " << srcReg << ", " << offsetReg << "\n"; // 将源指针和偏移量相加
    // 更新寄存器映射
    _regMap[dest] = destReg; // 将结果寄存器映射到目标变量
    // 如果需要，可以将结果存储到栈上
    _currentFrame.addLocal(dest, 4); // 假设每个元素是 i32，分配 4 字节
    int destOffset = _currentFrame.getOffset(dest);
    _textSection << "  sw " << destReg << ", " << destOffset << "(sp)\n"; // 将结果存储到栈上
}






std::string RiscvGenerator::getTempReg() {
    tempRegIndex = tempRegIndex % 7; // 使用 7 个临时寄存器 t0-t6
    if (_usedRegs[tempRegIndex]) {
        // 如果当前寄存器已被使用，把寄存器中的值存储到栈上
        std::string VarName;
        for (const auto &pair : _regMap) {
            if (pair.second == "t" + std::to_string(tempRegIndex)) {
                VarName = pair.first; // 找到对应的变量名
                break;
            }
        }
        if (!VarName.empty()) {
            int offset = _currentFrame.getOffset(VarName);
            _textSection << "  sw t" << tempRegIndex << ", " << offset << "(sp)\n"; // 将寄存器值存储到栈上
            _regMap.erase(VarName); // 从寄存器映射中移除
        }
    }
    _usedRegs[tempRegIndex] = true; // 标记寄存器为已使用
    return "t" + std::to_string(tempRegIndex++); // 返回 t0, t1, t2, ...
}