#ifndef RISCVGENERATOR_H
#define RISCVGENERATOR_H


#include "IRGenerator.h" // 引入你的LLVM IR数据结构
#include "RiscvFrame.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <variant>

// // 存储位置的类型
// enum class StorageType {
//     ON_STACK,       // 在栈上，需要通过帧指针(fp/s0)加偏移访问
//     IN_REGISTER,    // 在一个物理寄存器中
//     GLOBAL_VAR      // 是一个全局变量，通过标签访问
// };

// // 描述一个变量的具体位置
// struct VariableLocation {
//     StorageType type;

//     // 根据type的不同，只有一个成员有效
//     std::variant<int, std::string> location; // int for stack_offset, string for reg_name or global_label

//     // 辅助构造函数，方便使用
//     static VariableLocation onStack(int offset) {
//         return { StorageType::ON_STACK, offset };
//     }
//     static VariableLocation inRegister(const std::string &regName) {
//         return { StorageType::IN_REGISTER, regName };
//     }
//     static VariableLocation asGlobal(const std::string &label) {
//         return { StorageType::GLOBAL_VAR, label };
//     }
// };
struct GlobalVar {
    std::string label;
    GlobalVar(const std::string &lbl) : label(lbl) {}
};

class RiscvGenerator {
public:
    explicit RiscvGenerator(const LLVMModule &module);
    void generate(std::ostream &out); // 生成完整的汇编代码

private:
    std::vector<GlobalVar> _global_var;


    void generateFunction(const LLVMFunction &func);
    void generateGlobalVar(const LLVMGlobalVar &var);
    void generateBasicBlock(const LLVMBasicBlock &block);
    void generateInstruction(const std::string &instr);

    const LLVMModule &_module;
    RiscvFrame _currentFrame;

    // 用于虚拟寄存器到物理寄存器/栈位置的映射
    int _stackOffset; // 当前函数栈的偏移

    LLVMFunction _currentFunction; // 当前正在处理的函数

    std::stringstream _textSection;
    std::stringstream _dataSection;

    // 用于寄存器分配的映射表
   // key: LLVM虚拟寄存器名 (如 %1), value: RISC-V物理寄存器名 (如 t0) 或栈偏移
    std::unordered_map<std::string, std::string> _regMap;
    int _tempRegCounter; // 用于分配临时寄存器 t0, t1, ...

    // === 辅助函数 ===
    std::string getTempReg(); // 获取一个临时寄存器
    void freeTempReg(const std::string &reg); // 释放临时寄存器
    std::string loadToReg(const std::string &llvmVar); // 将变量从栈加载到寄存器
    void storeFromReg(const std::string &llvmVar, const std::string &reg); // 将寄存器值存回栈



    // 不同的指令生成函数
    void generateAlloca(const LLVM_INS &instr);
    void generateBitCast(const LLVM_INS &instr);
    void generateMemcpy(const LLVM_INS &instr);
    void generateLoad(const LLVM_INS &instr);
    void generateStore(const LLVM_INS &instr);
    void generateArithmetic(const LLVM_INS &instr);
    void generateBranch(const LLVM_INS &instr);
    void generateGetElementPtr(const LLVM_INS &instr);
    void generateZext(const LLVM_INS &instr);
    void generatePhi(const LLVM_INS &instr);
    void generateNot(const LLVM_INS &instr);
    void generateAssign(const LLVM_INS &instr);
    void generateCall(const LLVM_INS &instr);
    void generateRet(const LLVM_INS &instr);

    // 关键！从LLVM变量名 (e.g., "%1") 到其存储位置的映射
    // std::unordered_map<std::string, VariableLocation> _locationMap;

    // 辅助方法
    // 将一个变量加载到临时寄存器中，并返回该寄存器名
    // std::string loadVarToRegister(const std::string &varName);

};

#endif // RISCVGENERATOR_H