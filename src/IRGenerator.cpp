#include "IRGenerator.h"

std::string TypeToLLVM(const VarType &type) {
    std::string llvmType;

    switch (type.baseType) {
    case BaseType::I1:
        llvmType = "i1";
        break;
    case BaseType::I8:
        llvmType = "i8";
        break;
    case BaseType::I32:
        llvmType = "i32";
        break;
    case BaseType::FLOAT:
        llvmType = "float";
        break;
    case BaseType::DOUBLE:
        llvmType = "double";
        break;
    default:
        llvmType = "void";
        break;
    }
    if (type.isArray()) {
        for (int i = type.dimSizes.size() - 1; i >= 0; i--) {
            int dim = type.dimSizes[i];
            if (dim == -1) { // to check
                llvmType = llvmType + "*";
            } else {
                llvmType = "[" + std::to_string(dim) + " x " + llvmType + "]";
            }
        }
    }
    return llvmType;
}
std::string BTypeToLLVM(const BaseType &type) {
    switch (type) {
    case BaseType::I1:
        return "i1";
    case BaseType::I8:
        return "i8";
    case BaseType::I32:
        return "i32";
    case BaseType::FLOAT:
        return "float";
    case BaseType::DOUBLE:
        return "double";
    default:
        return "void";
    }
}

// ================ Basic Block
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

// =============== Function
LLVMFunction::LLVMFunction(std::string name, std::string retT, std::vector<LLVMValue> params)
    : name(std::move(name)), returnType(std::move(retT)), parameters(std::move(params)) {
}

void LLVMFunction::addBasicBlock(LLVMBasicBlock *block) {
    basicblocks.push_back(block);
}

std::string LLVMFunction::toString()const {
    std::stringstream ss;
    ss << "define " << returnType << " @" << name << "(";
    for (size_t i = 0; i < parameters.size(); ++i) {
        ss << TypeToLLVM(parameters[i].type) << " " << "%" << parameters[i].name + "_params";
        if (i < parameters.size() - 1) {
            ss << ", ";
        }
    }
    ss << ") {\n";
    for (const auto &block : basicblocks) {
        ss << block->toString();
    }
    ss << "}\n";
    return ss.str();
}

std::string LLVMFunction::newTmp(std::string prefix) {
    return prefix + std::to_string(tmpCounter++);
}

// =============== Global Variable
LLVMGlobalVar::LLVMGlobalVar(std::string name, VarType type, std::string initValue, bool isConstant) {
    std::stringstream ss;
    if (type.isFunction) {
        ss << "declare " << TypeToLLVM(type) << " @" << name << "(";
        if (!initValue.empty()) {
            ss << TypeToLLVM(type) << " " << initValue;
        }        
        ss << ")\n";
    } else {
        ss << "@" << name << " =";
        if (isConstant) {
            ss << " constant";
        } else {
            ss << " global";
        }
        if (!initValue.empty()) {
            ss << " " << initValue;
        } else {
            ss << " " << TypeToLLVM(type) << " zeroinitializer";
        }
        ss << "\n";
    }
    instruction = std::move(ss.str());
}
std::string LLVMGlobalVar::toString() const {
    return instruction;
}

// =============== Module
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