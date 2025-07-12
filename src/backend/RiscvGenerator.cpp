#include "RiscvGenerator.h"
#include <regex>


RiscvGenerator::RiscvGenerator(const LLVMModule &module) :_module (module), _tempRegCounter(0){
};

void RiscvGenerator::generate(std::ostream &out) {
    // 1. 生成 .data 段 (全局变量)
    _dataSection << ".data\n";
    for (const auto& entry : _module.entries) {
        if (std::holds_alternative<LLVMGlobalVar>(entry)) {
            generateGlobalVar(std::get<LLVMGlobalVar>(entry));
        }
    }

    // 2. 生成 .text 段 (函数代码)
    _textSection << ".text\n";
    for (const auto& entry : _module.entries) {
        if (std::holds_alternative<LLVMFunction>(entry)) {
            const auto& func = std::get<LLVMFunction>(entry);
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


void RiscvGenerator::generateGlobalVar(const LLVMGlobalVar& var) {
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
        } else if (var.type.baseType == BaseType::I8 || var.type.baseType == BaseType::I1)  {
            // i8类型使用 .byte 指令
            _dataSection << "  .byte " << initVal << "\n";
        }
    }
    _dataSection << "\n"; // 在每个全局变量定义后加一个空行，更美观
}
