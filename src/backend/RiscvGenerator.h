#ifndef RISCVGENERATOR_H
#define RISCVGENERATOR_H


#include "IRGenerator.h" // 引入你的LLVM IR数据结构
#include "RiscvFrame.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class RiscvGenerator {
public:
    explicit RiscvGenerator(const LLVMModule& module);
    void generate(std::ostream& out); // 生成完整的汇编代码

private:
    void generateFunction(const LLVMFunction& func);
    void generateGlobalVar(const LLVMGlobalVar& var);
    void generateBasicBlock(const LLVMBasicBlock& block);
    void generateInstruction(const std::string& instr);

    const LLVMModule& _module;
    RiscvFrame _currentFrame;

    // 用于虚拟寄存器到物理寄存器/栈位置的映射
    int _stackOffset; // 当前函数栈的偏移

    std::stringstream _textSection;
    std::stringstream _dataSection;

    // 用于寄存器分配的映射表
   // key: LLVM虚拟寄存器名 (如 %1), value: RISC-V物理寄存器名 (如 t0) 或栈偏移
    std::unordered_map<std::string, std::string> _regMap;
    int _tempRegCounter; // 用于分配临时寄存器 t0, t1, ...

    // === 辅助函数 ===
    std::string getTempReg(); // 获取一个临时寄存器
    void freeTempReg(const std::string& reg); // 释放临时寄存器
    std::string loadToReg(const std::string& llvmVar); // 将变量从栈加载到寄存器
    void storeFromReg(const std::string& llvmVar, const std::string& reg); // 将寄存器值存回栈
};

#endif // RISCVGENERATOR_H