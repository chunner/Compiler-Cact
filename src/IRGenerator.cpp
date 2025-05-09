#include "IRGenerator.h"

LLVMBasicBlock::LLVMBasicBlock(std::string label) : label(std::move(label)) {

}

void LLVMBasicBlock::addInstruction(const std::string &instruction) {
    instructions.push_back(instruction);
}

std::string LLVMBasicBlock::toString() const {
    std::stringstream ss;
    if (!label.empty()) {
        ss << label << ":\n";
    }
    for (const auto &instr : instructions) {
        ss << "  " << instr << "\n";
    }
    return ss.str();
}

LLVMFunction::LLVMFunction(std::string name, std::string retT, std::vector<LLVMValue> params)
    : name(std::move(name)), returnType(std::move(retT)), parameters(std::move(params)) {
}

void LLVMFunction::addBasicBlock(const LLVMBasicBlock &block) {
    basicblocks.push_back(block);
}

std::string LLVMFunction::toString()const {
    std::stringstream ss;
    ss << "define " << returnType << "" << name << "(";
    for (size_t i = 0; i < parameters.size(); ++i) {
        ss << parameters[i].type << " " << parameters[i].name;
        if (i < parameters.size() - 1) {
            ss << ", ";
        }
    }
    ss << ") {\n";
    for (const auto &block : basicblocks) {
        ss << block.toString();
    }
    ss << "}\n";
    return ss.str();
}


void LLVMModule::addFunction(const LLVMFunction &function) {
    functions.push_back(function);
}

void LLVMModule::addGlobalVar(const LLVMBasicBlock &globalVar) {
    globalVars.push_back(globalVar);
}

std::string LLVMModule::toString()const {
    std::stringstream ss;
    for (const auto &globalVar : globalVars) {
        ss << globalVar.toString();
    }
    for (const auto &function : functions) {
        ss << function.toString() << "\n";
    }
    return ss.str();
}