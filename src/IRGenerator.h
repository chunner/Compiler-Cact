#ifndef IRGENERATOR_H
#define IRGENERATOR_H

#include <string>
#include <vector>
#include <sstream>
struct LLVMValue {
    std::string name;
    std::string type;

    LLVMValue(std::string name, std::string type) : name(name), type(type) {}
};

class LLVMBasicBlock {
public:
    std::string label;
    std::vector<std::string> instructions;
    LLVMBasicBlock(std::string label);
    void addInstruction(const std::string &instructions);
    std::string toString() const;
};

class LLVMFunction {
public:
    std::string name;
    std::string returnType;
    std::vector<LLVMValue> parameters;
    std::vector<LLVMBasicBlock> basicblocks;
    LLVMFunction(std::string name, std::string retT, std::vector<LLVMValue> params);
    void addBasicBlock(const LLVMBasicBlock &block);
    std::string toString()const;
};

class LLVMModule {
public:
    std::vector<LLVMFunction> functions;
    std::vector<LLVMBasicBlock> globalVars;
    void addFunction(const LLVMFunction &function);
    void addGlobalVar(const LLVMBasicBlock &globalVar);
    std::string toString() const;
};

#endif