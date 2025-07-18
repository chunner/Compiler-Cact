#ifndef IRGENERATOR_H
#define IRGENERATOR_H

#include <string>
#include <vector>
#include <sstream>
#include <variant>
#include "Types.h"



std::string TypeToLLVM(const VarType &type);
std::string BTypeToLLVM(const BaseType &type);

enum class LLVM_INS_T {
    ALLOCA,
    BITCAST,
    MEMCPY,
    MEMSET,
    LOAD,
    STORE,
    BR,
    GEP,
    ZEXT,
    PHI,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    FADD,
    FSUB,
    FMUL,
    FDIV,
    AND,
    OR,
    NOT,
    EQ,
    NEQ,
    LT,
    GT,
    LE,
    GE,
    FLT,
    FGT,
    FLE,
    FGE,
    ASSIGN,
    CALL,
    RET
};
class LLVM_INS {
public:
    LLVM_INS_T type;
    std::string result; // Result variable name
    std::vector<std::string> operands; // Operands for the instruction
    LLVM_INS(LLVM_INS_T t, std::string res, std::vector<std::string> ops)
        : type(t), result(std::move(res)), operands(std::move(ops)) {
    };

};

class LLVMBasicBlock {
public:
    std::string label;
    std::vector<std::string> instructions;
    std::vector<LLVM_INS> llvm_ins;
    LLVMBasicBlock(std::string label) : label(std::move(label)) {
    };
    void addInstruction(const std::string &instruction);
    void addLLVMInstruction(const LLVM_INS &instruction);
    std::string toString() const;
};

class LLVMFunction {
public:
    std::string name;
    std::string returnType;
    std::vector<LLVMValue> parameters;
    std::vector<LLVMBasicBlock *> basicblocks;
    LLVMFunction(std::string name, std::string retT, std::vector<LLVMValue> params);
    void addBasicBlock(LLVMBasicBlock *block);
    std::string toString()const;
    LLVMFunction() = default;
};

class LLVMGlobalVar {
public:
    std::string instruction;
    std::string name;
    VarType type;
    std::string initValue;
    bool isConstant;
    LLVMGlobalVar(std::string name, VarType type, std::string initValue, bool isConstant);
    std::string toString() const;
};

class LLVMModule {
public:
    using ModuleEntry = std::variant<LLVMFunction, LLVMGlobalVar>;
    std::vector<ModuleEntry> entries;
    void addFunction(const LLVMFunction &function);
    void addGlobalVar(const LLVMGlobalVar &globalVar);
    std::string toString() const;
};

#endif