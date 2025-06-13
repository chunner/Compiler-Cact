#ifndef IRGENERATOR_H
#define IRGENERATOR_H

#include <string>
#include <vector>
#include <sstream>
#include <variant>
#include "Types.h"



std::string TypeToLLVM(const VarType &type);
std::string BTypeToLLVM(const BaseType &type);



class LLVMBasicBlock {
public:
    std::string label;
    std::vector<std::string> instructions;
    LLVMBasicBlock(std::string label) : label(std::move(label)) {
    };
    void addInstruction(const std::string &instruction);
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
};

class LLVMGlobalVar {
public:
    std::string instruction;
    // std::string name;
    // std::string type;
    // std::string initValue;
    // bool isConstant;
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