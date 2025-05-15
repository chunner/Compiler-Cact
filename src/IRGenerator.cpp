#include "IRGenerator.h"

std::string mapCactTypeToLLVM(const VarType &type) {
    std::string llvmType;

    switch (type.baseType) {
    case BaseType::INT:
        llvmType = "i32";
        break;
    case BaseType::DOUBLE:
        llvmType = "double";
        break;
    case BaseType::CHAR:
        llvmType = "i8";
        break;
    case BaseType::FLOAT:
        llvmType = "float";
        break;
    default:
        llvmType = "void";
        break;
    }
    if (type.isArray()) {
        for (int dim : type.dimSizes) {
            if (dim == -1) {
                llvmType = llvmType + "*";
            } else {
                llvmType = "[" + std::to_string(dim) + " x " + llvmType + "]";
            }
        }
    }
    return llvmType;
}

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
        ss << parameters[i].type << " " << "%" << parameters[i].name;
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
LLVMGlobalVar::LLVMGlobalVar(std::string name, std::string type, std::string initValue, bool isConstant) {
    std::stringstream ss;
    ss << "@" << name << " =";
    if (isConstant) {
        ss << " constant";
    } else {
        ss << " global";
    }
    if (!initValue.empty()) {
        ss << " " << type << " " << initValue;
    } else {
        ss << " " << type;
    }
    ss << "\n";
    instruction = std::move(ss.str());
}
std::string LLVMGlobalVar::toString() const {
    return instruction;
}

void LLVMModule::addFunction(const LLVMFunction &function) {
    entries.emplace_back(function);
}

void LLVMModule::addGlobalVar(const LLVMGlobalVar &globalVar) {
    entries.emplace_back(globalVar);
}

std::string LLVMModule::toString()const {
    std::stringstream ss;
    for (const auto &entry : entries) {
        std::visit([&ss](const auto &e) {
            ss << e.toString();
            }, entry);
    }
    return ss.str();
}