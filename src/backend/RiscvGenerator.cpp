#include "RiscvGenerator.h"
#include <regex>


RiscvGenerator::RiscvGenerator(const LLVMModule &module) :_module(module), _tempRegCounter(0) {
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

    _dataSection << ".globl " << var.name << "\n";
    if (var.type.baseType == BaseType::DOUBLE) {
        // double类型需要8字节对齐
        _dataSection << ".align 3\n"; // 2^3 = 8 bytes
    } else if (var.type.baseType == BaseType::I32 || var.type.baseType == BaseType::FLOAT || var.type.baseType == BaseType::I8) {
        // i32, float, i8类型需要4字节对齐
        _dataSection << ".align 2\n"; // 2^2 = 4 bytes
    }
    _dataSection << var.name << ":\n";

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

    // 注册到变量-位置映射中
    _locationMap[var.name] = VariableLocation::asGlobal(var.name);
}

void RiscvGenerator::generateFunction(const LLVMFunction &func) {
    _textSection << ".globl " << func.name << "\n";
    _textSection << func.name << ":\n";

    _currentFrame = RiscvFrame(); // 新建栈帧
    _regMap.clear();             // 清空寄存器映射
    _tempRegCounter = 0;         // 重置临时寄存器计数器

    // 遍历所有指令，计算栈帧大小
    int frameSize;
    for (const auto &block : func.basicblocks) {
        for (const auto &inst : block->llvm_ins) {
            if (inst.type == LLVM_INS_T::ALLOCA) {
                frameSize += std::stoi(inst.operands[1]);
            }
        }
    }

    // --- 函数序言 (Prologue) ---
    _textSection << "  # Function Prologue\n";
    _textSection << "  addi sp, sp, -" << frameSize << "\n";
    _textSection << "  sd ra, " << frameSize - 8 << "(sp)\n";
    _textSection << "  sd s0, " << frameSize - 16 << "(sp)\n";
    _textSection << "  addi s0, sp, " << frameSize << "\n";

    // --- 函数体 ---
    for (const auto &block : func.basicblocks) {
        generateBasicBlock(*block);
    }

    // --- 函数尾声 (Epilogue) ---
    // 注意：真正的尾声应该在每个ret指令前生成
    // 这里放一个默认的，以防函数末尾没有显式返回
    _textSection << ".L" << func.name << "_exit:\n"; // 创建一个统一的退出点
    _textSection << "  # Function Epilogue\n";
    _textSection << "  ld ra, " << frameSize - 8 << "(sp)\n";
    _textSection << "  ld s0, " << frameSize - 16 << "(sp)\n";
    _textSection << "  addi sp, sp, " << frameSize << "\n";
    _textSection << "  jr ra\n\n";
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
        default:
            // 其他指令类型暂不处理
            break;
        }
    }
}

void RiscvGenerator::generateAlloca(const LLVM_INS &inst) {
    // 示例: %a = alloca i32
    // 转换:
    //   addi sp, sp, -4
    //   sw zero, 0(sp)

    std::string varName = inst.result;
    int size = std::stoi(inst.operands[1]); // 第二个操作数是分配的字节数

    _textSection << "  # Alloca " << varName << "\n";
    _textSection << "  addi sp, sp, -" << size << "\n";
    _textSection << "  sw zero, 0(sp)\n"; // 初始化为0

    // 更新内存映射
    _currentFrame.addLocal(varName, size);
    _locationMap[varName] = VariableLocation::onStack(_currentFrame.getCurrentOffset());

}

void RiscvGenerator::generateLoad(const LLVM_INS &inst) {
    // 示例: %a = load i32, i32* %b
    // 转换:
    //   lw t0, 0(b)
    //   sw t0, a

    std::string dest = inst.result; // 目标位置
    std::string srcPtr = inst.operands[1]; // 源指针

    // 分配临时寄存器
    std::string tempReg = getTempReg();

    _textSection << "  # Load " << dest << " from " << srcPtr << "\n";
    _textSection << "  lw " << tempReg << ", 0(" << srcPtr << ")\n"; // 从指针加载值
    _textSection << "  sw " << tempReg << ", " << dest << "\n"; // 存储到目标位置

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

    // 从寄存器或栈中获取源值
    std::string srcReg;
    if (_regMap.find(src) != _regMap.end()) {
        srcReg = _regMap[src]; // 如果在寄存器中
    } else {
        srcReg = getTempReg(); // 否则分配一个临时寄存器
        _textSection << "  lw " << srcReg << ", " << src << "\n"; // 从栈加载值
    }

    _textSection << "  # Store " << src << " to " << destPtr << "\n";
    _textSection << "  sw " << srcReg << ", 0(" << destPtr << ")\n"; // 存储到目标指针

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
    std::string op1 = inst.operands[0]; // 第一个操作数
    std::string op2 = inst.operands[1]; // 第二个操作数

    std::string tempReg1;
    std::string tempReg2;
    std::string resultReg;

    _textSection << "  # Arithmetic " << " " << dest << " = " << op1 << " op " << op2 << "\n";

    // 加载第一个操作数
    if (_regMap.find(op1) != _regMap.end()) {
        tempReg1 = _regMap[op1]; // 如果在寄存器中
    } else {
        tempReg1 = getTempReg(); // 否则分配一个临时寄存器
        _textSection << "  lw " << tempReg1 << ", " << op1 << "\n"; // 从栈加载
    }

    // 加载第二个操作数
    if (_regMap.find(op2) != _regMap.end()) {
        tempReg2 = _regMap[op2]; // 如果在寄存器中
    } else {
        tempReg2 = getTempReg(); // 否则分配一个临时寄存器
        _textSection << "  lw " << tempReg2 << ", " << op2 << "\n"; // 从栈加载
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
    //   ret
    if (inst.operands.empty()) {
        // 无返回值的函数
        _textSection << "  # Return from function\n";
        _textSection << "   ret\n";
    } else {
        // 有返回值的函数
        std::string retVal = inst.operands[0]; // 返回值

        if (_regMap.find(retVal) != _regMap.end()) {
            // 如果返回值在寄存器中
            _textSection << "  # Return " << retVal << " from function\n";
            _textSection << "  mv a0, " << _regMap[retVal] << "\n"; // 将返回值移动到 a0 寄存器
        } else {
            // 如果返回值在栈上
            _textSection << "  # Load return value " << retVal << " from stack\n";
            _textSection << "  lw a0, " << retVal << "\n"; // 从栈加载返回值
        }
        _textSection << "  ret\n";
    }
}