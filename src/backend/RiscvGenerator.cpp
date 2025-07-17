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
        if (!var.initValue.empty() && var.initValue != "zeroinitializer") {
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

    // 处理函数参数
    for (size_t i = 0; i < func.parameters.size(); ++i) {
        const auto &param = func.parameters[i];
        std::string paramName = param.name;
        // 更新寄存器映射
        _regMap[paramName] = "a" + std::to_string(i); // 假设参数寄存器从 a0 开始
    }

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
    _textSection << _currentFunction.name << "_" << block.label << ":\n";
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
        case LLVM_INS_T::MOD:
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
        case LLVM_INS_T::MEMCPY:
            generateMemcpy(inst);
            break;
        case LLVM_INS_T::BITCAST:
            generateBitCast(inst);
            break;
        case LLVM_INS_T::CALL:
            generateCall(inst);
            break;
        case LLVM_INS_T::NEQ:
        case LLVM_INS_T::EQ:
        case LLVM_INS_T::LT:
        case LLVM_INS_T::GT:
        case LLVM_INS_T::GE:
        case LLVM_INS_T::LE:
            generateIcmp(inst);
            break;
        case LLVM_INS_T::PHI:
            generatePhi(inst);
            break;
        case LLVM_INS_T::OR:
        case LLVM_INS_T::AND:
            generateLogical(inst);
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

    _currentFrame.addLocal(varName + "*", size);
    int offset = _currentFrame.getOffset(varName + "*");

    _currentFrame.addLocal(varName, 8);
    _textSection << "  # Alloca " << varName << " of size " << size << "\n";
    int varOffset = _currentFrame.getOffset(varName);
    std::string tempReg = getTempReg(); // 分配一个临时寄存器
    _textSection << "  addi " << tempReg << ", sp, " << offset << "\n"; // 将栈指针偏移量加载到临时寄存器
    _textSection << "  sd " << tempReg << ", " << varOffset << "(sp)\n"; // 将临时寄存器的值存储到栈上
}

void RiscvGenerator::generateLoad(const LLVM_INS &inst) {
    // 示例: %a = load i32, i32* %b
    // 转换:
    //   lw t1, b
    //   lw t0, 0(t1) // 假设 %b 在栈上
    //   sw t0, 4(sp)

    std::string dest = inst.result.substr(1); // 目标位置
    std::string srcPtr = inst.operands[1]; // 源指针
    bool global_src = srcPtr[0] == '@'; // 检查是否是全局变量
    if (srcPtr[0] == '%' || srcPtr[0] == '@') {
        srcPtr = srcPtr.substr(1); // 去掉前缀 '%'
    }

    _textSection << "  # Load " << dest << " from " << srcPtr << "\n";
    std::string tempReg;
    if (std::regex_match(srcPtr, std::regex(R"(\-?\d+)"))) {
        // 如果是立即数，直接将其加载到临时寄存器
        tempReg = getTempReg();
        _textSection << "  li " << tempReg << ", " << srcPtr << "\n"; // 将立即数加载到寄存器
    } else if (_regMap.find(srcPtr + "*") != _regMap.end()) {
        tempReg = _regMap[srcPtr + "*"]; // 如果在寄存器中
    } else if (global_src) {
        // 如果是全局变量，直接加载到临时寄存器
        tempReg = getTempReg();
        _textSection << "  lw " << tempReg << ", " << srcPtr << "\n"; // 从全局变量加载值
    } else {
        std::string addrReg = getTempReg(); // 分配一个临时寄存器来存储地址
        _textSection << "  ld " << addrReg << ", " << _currentFrame.getOffset(srcPtr) << "(sp)\n"; // 从栈加载地址
        tempReg = getTempReg(); // 分配一个新的临时寄存器来存储加载的值
        _textSection << "  lw " << tempReg << ", 0(" << addrReg << ")\n"; // 从地址加载值
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
    bool global_dest = destPtr[0] == '@'; // 检查是否是全局变量
    if (destPtr[0] == '%' || destPtr[0] == '@') {
        destPtr = destPtr.substr(1); // 去掉前缀 '%'
    }

    _textSection << "  # Store " << src << " to " << destPtr << "\n";
    // 将源操作数加载到临时寄存器
    std::string srcReg;
    if (std::regex_match(src, std::regex(R"(\-?\d+)"))) {
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
    std::string destReg;
    if (global_dest) {
        destReg = getTempReg();
        _textSection << "  la " << destReg << ", " << destPtr << "\n"; // 从全局变量加载地址
    } else if (_regMap.find(destPtr) != _regMap.end()) {
        destReg = _regMap[destPtr]; // 如果在寄存器中
    } else {
        destReg = getTempReg(); // 否则分配一个临时寄存器
        int offset = _currentFrame.getOffset(destPtr);
        // 从栈加载目标指针地址, 地址长度为8B
        _textSection << "  ld " << destReg << ", " << offset << "(sp)\n"; // 从栈加载地址
    }
    // 将源寄存器的值存储到目标指针地址
    _textSection << "  sw " << srcReg << ", 0(" << destReg << ")\n"; // 将值存储到目标地址

    // 更新寄存器映射
    // _regMap[destPtr + "*"] = srcReg;
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
    } else if (std::regex_match(op1, std::regex(R"(-?\d+)"))) {
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
    } else if (std::regex_match(op2, std::regex(R"(-?\d+)"))) {
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
    case LLVM_INS_T::MOD:
        _textSection << "  rem " << resultReg << ", " << tempReg1 << ", " << tempReg2 << "\n";
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
        if (targetLabel[0] == '%') {
            targetLabel = targetLabel.substr(1); // 去掉前缀 '%'
        }
        targetLabel = _currentFunction.name + "_" + targetLabel; // 添加函数名前缀
        _textSection << "  # Unconditional branch to " << targetLabel << "\n";
        _textSection << "  j " << targetLabel << "\n";
    } else if (inst.operands.size() == 3) {
        // 有条件跳转
        std::string cond = inst.operands[0]; // 条件
        bool global_cond = cond[0] == '@'; // 检查是否是全局变量
        if (cond[0] == '%' || cond[0] == '@') {
            cond = cond.substr(1); // 去掉前缀 '%'
        }
        std::string trueLabel = inst.operands[1]; // 真分支标签
        trueLabel = _currentFunction.name + "_" + trueLabel; // 添加函数名前缀
        std::string falseLabel = inst.operands[2]; // 假分支标签
        falseLabel = _currentFunction.name + "_" + falseLabel; // 添加函数名前缀

        std::string condReg;
        if (global_cond) {
            _textSection << "  # Conditional branch on global variable " << cond << "\n";
            condReg = getTempReg(); // 如果是全局变量，直接加载到临时寄存器
            _textSection << "  lw " << condReg << ", " << cond << "\n"; // 从全局变量加载值
            _textSection << "  andi " << condReg << ", " << condReg << ", 1\n"; // 确保条件是布尔值
            _textSection << "  beqz " << condReg << ", " << falseLabel << "\n"; // 如果条件为0，跳转到假分支
            _textSection << "  j " << trueLabel << "\n"; // 否则跳转到真分支
        } else if (_regMap.find(cond) != _regMap.end()) {
            // 如果条件在寄存器中
            _textSection << "  # Conditional branch on " << cond << "\n";
            _textSection << "  beqz " << _regMap[cond] << ", " << falseLabel << "\n"; // 如果条件为0，跳转到假分支
            _textSection << "  j " << trueLabel << "\n"; // 否则跳转到真分支
        } else {
            // 如果条件在栈上
            _textSection << "  # Conditional branch on stack variable " << cond << "\n";
            int offset = _currentFrame.getOffset(cond);
            std::string condReg = getTempReg(); // 分配一个临时寄存器
            _textSection << "  lw " << condReg << ", " << offset << "(sp)\n"; // 从栈加载条件值
            _textSection << "  andi " << condReg << ", " << condReg << ", 1\n"; // 确保条件是布尔值
            _textSection << "  beqz " << condReg << ", " << falseLabel << "\n"; // 如果条件为0，跳转到假分支
            _textSection << "  j " << trueLabel << "\n"; // 否则跳转到真分支
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
        if (std::regex_match(retVal, std::regex(R"(-?\d+)"))) {
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
    bool global_src = srcPtr[0] == '@'; // 检查是否是全局变量
    if (srcPtr[0] == '%' || srcPtr[0] == '@') {
        srcPtr = srcPtr.substr(1); // 去掉前缀 '%'
    }
    _textSection << "  # GEP " << dest << " from " << srcPtr << "\n";
    std::string srcReg;
    if (global_src) {
        srcReg = getTempReg(); // 如果是全局变量，直接加载到临时寄存器
        _textSection << " la " << srcReg << ", " << srcPtr << "\n"; // 从全局变量加载地址
    } else if (_regMap.find(srcPtr) != _regMap.end()) {
        srcReg = _regMap[srcPtr]; // 如果在寄存器中
    } else {
        srcReg = getTempReg(); // 否则分配一个临时寄存器
        int offset = _currentFrame.getOffset(srcPtr);
        _textSection << "  ld " << srcReg << ", " << offset << "(sp)\n"; // 从栈加载值
    }
    std::vector<std::string> indices;
    std::vector<int> indexlen;
    std::regex reIndex(R"(i32\s+((\d+)|(%[\w]+)))"); // 匹配 i32 后面的索引
    std::string instruction = instr.operands[0];
    while (std::regex_search(instruction, match, reIndex)) {
        std::string indexStr = match[1].str();
        if (std::regex_match(indexStr, std::regex(R"(\d+)"))) {
            indices.push_back(indexStr); // 如果是数字，直接添加到索引列表
        } else {
            // 如果是变量，查找寄存器映射
            if (indexStr[0] == '%' || indexStr[0] == '@') {
                indexStr = indexStr.substr(1); // 去掉前缀 '%'
            }
            if (_regMap.find(indexStr) != _regMap.end()) {
                std::string tempReg = getTempReg(); // 分配一个临时寄存器
                _textSection << "  mv " << tempReg << ", " << _regMap[indexStr] << "\n"; // 将寄存器值移动到临时寄存器
                indices.push_back(tempReg); // 将临时寄存器添加到索引列表
            } else {
                int offset = _currentFrame.getOffset(indexStr);
                std::string tempReg = getTempReg(); // 分配一个临时寄存器
                _textSection << "  lw " << tempReg << ", " << offset << "(sp)\n"; // 从栈加载值
                indices.push_back(tempReg); // 将临时寄存器添加到索引列表
            }
        }
        instruction = match.suffix().str(); // 更新指令字符串
    }
    std::regex reIndexLen(R"((\d+)\s+x)");
    instruction = instr.operands[0];
    while (std::regex_search(instruction, match, reIndexLen)) {
        indexlen.push_back(std::stoi(match[1].str()));
        instruction = match.suffix().str(); // 更新指令字符串
    }
    reverse(indices.begin(), indices.end());
    reverse(indexlen.begin(), indexlen.end());
    // 计算偏移量
    int offset = 0;
    int len = 1;
    std::string offsetReg = getTempReg(); // 分配一个临时寄存器来存储偏移量
    std::string indexReg = getTempReg(); // 分配一个临时寄存器来存储索引值
    std::string indexLenReg = getTempReg();
    _textSection << "  # Calculate GEP offset for " << dest << "\n";
    _textSection << "  li " << offsetReg << ", 0\n"; // 初始化偏移量寄存器为0
    for (size_t i = 0; i < indices.size(); ++i) {
        int index;
        if (std::regex_match(indices[i], std::regex(R"(\d+)"))) {
            index = std::stoi(indices[i]); // 如果是数字，直接转换
            _textSection << "  li " << indexReg << ", " << index << "\n"; // 将数字加载到临时寄存器
        } else {
            _textSection << "  mv " << indexReg << ", " << indices[i] << "\n"; // 如果是寄存器，直接移动
        }
        _textSection << "  li " << indexLenReg << ", " << (len * 4) << "\n"; // 假设每个元素是 i32，乘以 4
        _textSection << "  mul " << indexReg << ", " << indexReg << ", " << indexLenReg << "\n"; // 将索引寄存器乘以元素长度
        _textSection << "  add " << offsetReg << ", " << offsetReg << ", " << indexReg << "\n"; // 将偏移量寄存器加上索引寄存器
        // offset += index * (len * 4); // 假设每个元素是 i32，乘以 4
        len *= indexlen[i];
    }

    // // 将偏移量加载到临时寄存器
    // std::string offsetReg = getTempReg();
    // _textSection << "  li " << offsetReg << ", " << offset << "\n"; // 将偏移量加载到寄存器
    // 计算最终地址
    std::string destReg = getTempReg(); // 分配一个新的临时寄存器来存储结果地址
    _textSection << "  add " << destReg << ", " << srcReg << ", " << offsetReg << "\n"; // 将源指针和偏移量相加
    // 更新寄存器映射
    _regMap[dest] = destReg; // 将结果寄存器映射到目标变量
    // 将结果存储到栈上
    _currentFrame.addLocal(dest, 8); // 地址长度为8B
    int destOffset = _currentFrame.getOffset(dest);
    _textSection << "  sd " << destReg << ", " << destOffset << "(sp)\n"; // 将结果存储到栈上
}

void RiscvGenerator::generateMemcpy(const LLVM_INS &intr) {
    // 示例: call void @llvm.memcpy.p0i8.p0i8.i32(i8* %cast_i8_a3, i8* %cast_i8_global4, i32 32, i1 false)
    // 转换:
    //   addi t0, sp, 0
    //   la t1, cast_i8_global4
    //   li t2, 32
    //copy_loop:
    //   beqz t2, copy_done
    //   lb t3, 0(t1)
    //   sb t3, 0(t0)
    //   addi t0, t0, 1
    //   addi t1, t1, 1
    //   addi t2, t2, -1
    //   j copy_loop
    //copy_done:
    std::string dest = intr.operands[0];
    if (dest[0] == '%' || dest[0] == '@') {
        dest = dest.substr(1); // 去掉前缀 '%'
    }
    std::string src = intr.operands[1];
    if (src[0] == '%' || src[0] == '@') {
        src = src.substr(1); // 去掉前缀 '%'
    }
    std::string size = intr.operands[2];

    std::string destReg = getTempReg(); // 分配一个临时寄存器来存储目标地址
    int offset = _currentFrame.getOffset(dest);
    _textSection << "  # Memcpy from " << src << " to " << dest << " of size " << size << "\n";
    _textSection << "  ld " << destReg << ", " << offset << "(sp)\n"; // 从栈加载目标地址
    std::string srcReg;
    if (_regMap.find(src) != _regMap.end()) {
        srcReg = _regMap[src]; // 如果在寄存器中
    } else {
        srcReg = getTempReg(); // 否则分配一个临时寄存器
        int srcOffset = _currentFrame.getOffset(src);
        _textSection << "  lw " << srcReg << ", " << srcOffset << "(sp)\n"; // 从栈加载值
    }

    std::string sizeReg = getTempReg(); // 分配一个临时寄存器来存储大小
    _textSection << "  li " << sizeReg << ", " << size << "\n"; // 将大小加载到寄存器

    std::string dataReg = getTempReg(); // 分配一个临时寄存器来存储数据
    _textSection << "copy_" << dest << ":\n";
    _textSection << "  beqz " << sizeReg << ", copy_done_" << dest << "\n"; // 如果大小为0，跳转到结束
    _textSection << "  lb " << dataReg << ", 0(" << srcReg << ")\n"; // 从源地址加载一个字节到 t0
    _textSection << "  sb " << dataReg << ", 0(" << destReg << ")\n"; // 将字节存储到目标地址
    _textSection << "  addi " << destReg << ", " << destReg << ", 1\n"; // 目标地址加1
    _textSection << "  addi " << srcReg << ", " << srcReg << ", 1\n"; // 源地址加1
    _textSection << "  addi " << sizeReg << ", " << sizeReg << ", -1\n"; // 大小减1
    _textSection << "  j copy_" << dest << "\n"; // 跳转回循环开始
    _textSection << "copy_done_" << dest << ":\n"; // 结束标签

}

void RiscvGenerator::generateBitCast(const LLVM_INS &intr) {
    // 示例: %cast_i8_a3 = bitcast [4 x [2 x i32]]* %a1 to i8*

    std::string dest = intr.result;
    if (dest[0] == '%' || dest[0] == '@') {
        dest = dest.substr(1); // 去掉前缀 '%'
    }
    std::string src = intr.operands[0];
    bool global_src = src[0] == '@'; // 检查是否是全局变量
    if (src[0] == '%' || src[0] == '@') {
        src = src.substr(1); // 去掉前缀 '%'
    }
    if (global_src) {
        std::string tempReg = getTempReg();
        _textSection << "  # Bitcast " << src << " to " << dest << "\n";
        _textSection << "  la " << tempReg << ", " << src << "\n"; // 将全局变量地址加载到临时寄存器

        _currentFrame.addLocal(dest, 8); // 假设 i8* 占用 8 字节
        int offset = _currentFrame.getOffset(dest);
        _textSection << "  sd " << tempReg << ", " << offset << "(sp)\n"; // 将地址存储到栈上
        _regMap[dest] = tempReg; // 更新寄存器映射
    } else {
        _currentFrame.bitCast(src, dest);
    }

}

void RiscvGenerator::generateCall(const LLVM_INS &intr) {
    // 示例: call void @foo(i32 %a, i32 %b)
    // 转换:
    //   mv a0, a
    //   mv a1, b
    //   jal foo

    std::string funcName = intr.operands[0]; // 函数名
    if (funcName[0] == '@') {
        funcName = funcName.substr(1); // 去掉前缀 '@'
    }

    _textSection << "  # Call function " << funcName << "\n";

    // 准备参数寄存器
    std::regex re(R"((%|@)\w+|(\s\-?\d+))");
    std::string params = intr.operands[1];
    std::smatch match;
    int paramCnt = 0;
    while (std::regex_search(params, match, re)) {
        std::string arg = match[0].str(); // 提取参数名
        params = match.suffix().str(); // 更新参数字符串
        bool global_arg = arg[0] == '@'; // 检查是否是全局变量
        if (arg[0] == '%' || arg[0] == '@') {
            arg = arg.substr(1); // 去掉前缀 '%'
        }
        if (std::regex_match(arg, std::regex(R"(\s\-?\d+)"))) {
            // 如果是立即数，直接将其加载到寄存器
            _textSection << "   li a" << paramCnt++ << ", " << arg << "\n"; // 将立即数加载到寄存器
        }else if (global_arg) {
            // 如果是全局变量，直接加载到寄存器
            _textSection << "   lw a" << paramCnt++ << ", " << arg << "\n"; // 从全局变量加载值
        } else if (_regMap.find(arg) != _regMap.end()) {
            // 如果在寄存器中
            _textSection << "  mv a" << paramCnt++ << ", " << _regMap[arg] << "\n"; // 将寄存器值传递给参数寄存器
        } else {
            // 否则从栈加载值
            int offset = _currentFrame.getOffset(arg);
            _textSection << "   lw a" << paramCnt << ", " << offset << "(sp)\n"; // 从栈加载值
        }

    }
    _textSection << "  jal " << funcName << "\n"; // 调用函数

    // 如果函数有返回值，假设返回值在 a0 寄存器中
    if (!intr.result.empty()) {
        std::string retVar = intr.result.substr(1); // 去掉前缀 '%'
        _regMap[retVar] = "a0"; // 更新寄存器映射
        _currentFrame.addLocal(retVar, 4); // 假设返回值是 i32，分配 4 字节
        int offset = _currentFrame.getOffset(retVar);
        _textSection << "  sw a0, " << offset << "(sp)\n"; // 将返回值存储到栈上
    }
}

void RiscvGenerator::generateIcmp(const LLVM_INS &intr) {
    // 示例: %c = icmp ne i32 %a, %b
    // 转换:
    //   lw t0, a
    //   lw t1, b
    //   li t2, 0
    //   bne t0, t1, neq_label
    //   li t2, 1
    //neq_label:
    std::string dest = intr.result; // 目标位置
    if (dest[0] == '%' || dest[0] == '@') {
        dest = dest.substr(1); // 去掉前缀 '%'
    }
    std::string op1 = intr.operands[0]; // 第一个操作数
    bool global_op1 = op1[0] == '@'; // 检查是否是全局变量
    if (op1[0] == '%' || op1[0] == '@') {
        op1 = op1.substr(1); // 去掉前缀 '%'
    }
    std::string op2 = intr.operands[1]; // 第二个操作数
    bool global_op2 = op2[0] == '@'; // 检查是否是全局变量
    if (op2[0] == '%' || op2[0] == '@') {
        op2 = op2.substr(1); // 去掉前缀 '%'
    }

    std::string tempReg1;
    std::string tempReg2;
    std::string resultReg;

    _textSection << "  # Icmp" << " " << dest << " = " << op1 << " != " << op2 << "\n";

    // 加载第一个操作数
    if (_regMap.find(op1) != _regMap.end()) {
        tempReg1 = _regMap[op1]; // 如果在寄存器中
    } else if (global_op1) {
        // 如果是全局变量，直接加载到临时寄存器
        tempReg1 = getTempReg();
        _textSection << "  lw " << tempReg1 << ", " << op1 << "\n"; // 从全局变量加载值
    } else if (std::regex_match(op1, std::regex(R"(-?\d+)"))) {
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
    } else if (std::regex_match(op2, std::regex(R"(-?\d+)"))) {
        // 如果是立即数，直接将其加载到临时寄存器
        tempReg2 = getTempReg();
        _textSection << "  li " << tempReg2 << ", " << op2 << "\n"; // 将立即数加载到寄存器
    } else {
        tempReg2 = getTempReg(); // 否则分配一个临时寄存器
        int offset = _currentFrame.getOffset(op2);
        _textSection << "  lw " << tempReg2 << ", " << offset << "(sp)\n"; // 从栈加载值
    }
    // 执行不等于比较
    resultReg = getTempReg(); // 分配一个新的临时寄存器来存储结果
    _textSection << "  li " << resultReg << ", 1\n"; // 默认结果为0
    if (intr.type == LLVM_INS_T::NEQ) {
        _textSection << "  bne " << tempReg1 << ", " << tempReg2 << ", Icmp_" << dest << "\n"; // 如果不相等，跳转到 neq 标签
    } else if (intr.type == LLVM_INS_T::EQ) {
        _textSection << "  beq " << tempReg1 << ", " << tempReg2 << ", Icmp_" << dest << "\n"; // 如果相等，跳转到 eq 标签
    } else if (intr.type == LLVM_INS_T::LT) {
        _textSection << "  blt " << tempReg1 << ", " << tempReg2 << ", Icmp_" << dest << "\n"; // 如果小于，跳转到 lt 标签
    }else if (intr.type == LLVM_INS_T::GT) {
        _textSection << "  bgt " << tempReg1 << ", " << tempReg2 << ", Icmp_" << dest << "\n"; // 如果大于，跳转到 gt 标签
    } else if (intr.type == LLVM_INS_T::LE) {
        _textSection << "  ble " << tempReg1 << ", " << tempReg2 << ", Icmp_" << dest << "\n"; // 如果小于等于，跳转到 le 标签
    } else if (intr.type == LLVM_INS_T::GE) {
        _textSection << "  bge " << tempReg1 << ", " << tempReg2 << ", Icmp_" << dest << "\n"; // 如果大于等于，跳转到 ge 标签
    }
    _textSection << "  li " << resultReg << ", 0\n"; // 如果相等，结果为1
    _textSection << "Icmp_" << dest << ":\n"; // neq 标签
    // 更新寄存器映射
    _regMap[dest] = resultReg; // 将结果寄存器映射到目标变量
    // 将结果存储到栈上
    _currentFrame.addLocal(dest, 4);
    int destOffset = _currentFrame.getOffset(dest);
    _textSection << "  sw " << resultReg << ", " << destOffset << "(sp)\n"; // 将结果存储到栈上
}

void RiscvGenerator::generatePhi(const LLVM_INS &intr) {
    // 示例: %a = phi i32 [ 1, %bb1 ], [ 2, %bb2 ]

    std::string resReg = "s1";
    if (intr.result == "1") {
        std::string phiSource = intr.operands[0];
        if (phiSource[0] == '%' || phiSource[0] == '@') {
            phiSource = phiSource.substr(1); // 去掉前缀 '%'
        }
        _textSection << "  # Phi source" << "\n";
        if (phiSource == "true") {
            _textSection << "  li " << resReg << ", 1\n"; // 将 true 转换为 1
        }else if (phiSource == "false") {
            _textSection << "   li " << resReg << ", 0\n"; // 将 false 转换为 0
        }else if (std::regex_match(phiSource, std::regex(R"(-?\d+)"))) {
            _textSection << "  li " << resReg << ", " << phiSource << "\n"; // 如果是立即数，直接加载到寄存器
        } else {
            // 如果是变量，检查是否在寄存器中
            if (_regMap.find(phiSource) != _regMap.end()) {
                _textSection << "  mv " << resReg << ", " << _regMap[phiSource] << "\n"; // 如果在寄存器中
            } else {
                int offset = _currentFrame.getOffset(phiSource);
                _textSection << "  lw " << resReg << ", " << offset << "(sp)\n"; // 从栈加载值
                _textSection << "   andi " << resReg << ", " << resReg << ", 1\n"; // 确保结果是布尔值
            }
        }
        return;
    }
    std::string dest = intr.result; // 目标位置
    if (dest[0] == '%' || dest[0] == '@') {
        dest = dest.substr(1); // 去掉前缀 '%'
    }
    _textSection << "  # Phi instruction for " << dest << "\n";
    std::string phiReg = getTempReg(); // 分配一个临时寄存器来存储结果
    _textSection << "   mv " << phiReg << ", " << resReg << "\n"; // 初始化结果寄存器
    _regMap[dest] = phiReg; // 更新寄存器映射
    _currentFrame.addLocal(dest, 4); // 假设每个元素是 i32，分配 4 字节
    int destOffset = _currentFrame.getOffset(dest);
    _textSection << "  sw " << phiReg << ", " << destOffset << "(sp)\n"; // 将结果存储到栈上
}

void RiscvGenerator::generateLogical(const LLVM_INS &intr) {
    // 示例: %c = and i32 %a, %b
    // 转换:
    //   lw t0, a
    //   lw t1, b
    //   and t2, t0, t1
    //   sw t2, c

    std::string dest = intr.result; // 目标位置
    if (dest[0] == '%' || dest[0] == '@') {
        dest = dest.substr(1); // 去掉前缀 '%'
    }
    std::string op1 = intr.operands[0]; // 第一个操作数
    bool global_op1 = op1[0] == '@'; // 检查是否是全局变量
    if (op1[0] == '%' || op1[0] == '@') {
        op1 = op1.substr(1); // 去掉前缀 '%'
    }
    std::string op2 = intr.operands[1]; // 第二个操作数
    bool global_op2 = op2[0] == '@'; // 检查是否是全局变量
    if (op2[0] == '%' || op2[0] == '@') {
        op2 = op2.substr(1); // 去掉前缀 '%'
    }

    std::string tempReg1;
    std::string tempReg2;
    std::string resultReg;

    _textSection << "  # Logical operation " << dest << " = " << op1 << " " << "op" << " " << op2 << "\n";

    // 加载第一个操作数
    if (_regMap.find(op1) != _regMap.end()) {
        tempReg1 = _regMap[op1]; // 如果在寄存器中
    } else if (global_op1) {
        // 如果是全局变量，直接加载到临时寄存器
        tempReg1 = getTempReg();
        _textSection << "  lw " << tempReg1 << ", " << op1 << "\n"; // 从全局变量加载值
        _textSection << "  andi " << tempReg1 << ", " << tempReg1 << ", 1\n"; // 确保条件是布尔值
    } else if (std::regex_match(op1, std::regex(R"(-?\d+)"))) {
        // 如果是立即数，直接将其加载到临时寄存器
        tempReg1 = getTempReg();
        _textSection << "  li " << tempReg1 << ", " << op1 << "\n"; // 将立即数加载到寄存器
    } else {
        tempReg1 = getTempReg(); // 否则分配一个临时寄存器
        int offset = _currentFrame.getOffset(op1);
        _textSection << "  lw " << tempReg1 << ", " << offset << "(sp)\n"; // 从栈加载值
        _textSection << "  andi " << tempReg1 << ", " << tempReg1 << ", 1\n"; // 确保条件是布尔值
    }
    // 加载第二个操作数
    if (_regMap.find(op2) != _regMap.end()) {
        tempReg2 = _regMap[op2]; // 如果在寄存器中
    } else if (global_op2) {
        // 如果是全局变量，直接加载到临时寄存器
        tempReg2 = getTempReg();
        _textSection << "  lw " << tempReg2 << ", " << op2 << "\n"; // 从全局变量加载值
        _textSection << "  andi " << tempReg2 << ", " << tempReg2 << ", 1\n"; // 确保条件是布尔值
    } else if (std::regex_match(op2, std::regex(R"(-?\d+)"))) {
        // 如果是立即数，直接将其加载到临时寄存器
        tempReg2 = getTempReg();
        _textSection << "  li " << tempReg2 << ", " << op2 << "\n"; // 将立即数加载到寄存器
    } else {
        tempReg2 = getTempReg(); // 否则分配一个临时寄存器
        int offset = _currentFrame.getOffset(op2);
        _textSection << "  lw " << tempReg2 << ", " << offset << "(sp)\n"; // 从栈加载值
        _textSection << "  andi " << tempReg2 << ", " << tempReg2 << ", 1\n"; // 确保条件是布尔值
    }
    // 执行逻辑操作
    resultReg = getTempReg(); // 分配一个新的临时寄存器来存储结果
    if (intr.type == LLVM_INS_T::AND) {
        _textSection << "  and " << resultReg << ", " << tempReg1 << ", " << tempReg2 << "\n"; // 执行与操作
    } else if (intr.type == LLVM_INS_T::OR) {
        _textSection << "  or " << resultReg << ", " << tempReg1 << ", " << tempReg2 << "\n"; // 执行或操作
    } else {
        throw std::runtime_error("Unsupported logical operation type");
    }
    // 更新寄存器映射
    _regMap[dest] = resultReg; // 将结果寄存器映射到目标变量
    // 将结果存储到栈上
    _currentFrame.addLocal(dest, 4); // 假设每个元素是 i32，分配 4 字节
    int destOffset = _currentFrame.getOffset(dest);
    _textSection << "  sw " << resultReg << ", " << destOffset << "(sp)\n"; // 将结果存储到栈上
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
        if (!VarName.empty() && _currentFrame.hasLocal(VarName)) {
            int offset = _currentFrame.getOffset(VarName);
            _textSection << "  # Storing t" << tempRegIndex << " to stack for variable " << VarName << "\n";
            _textSection << "  sw t" << tempRegIndex << ", " << offset << "(sp)\n"; // 将寄存器值存储到栈上
            _regMap.erase(VarName); // 从寄存器映射中移除
        }
    }
    _usedRegs[tempRegIndex] = true; // 标记寄存器为已使用
    return "t" + std::to_string(tempRegIndex++); // 返回 t0, t1, t2, ...
}