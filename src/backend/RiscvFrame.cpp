#include "RiscvFrame.h"
#include <iostream>

std::string ssa2riscv(std::string ssa) {
    if (ssa[0] == '%' || ssa[0] == '@') {
        return ssa.substr(1);
    }
    return ssa;
}

void RiscvFrame::addLocal(const std::string &name, int size) {
    _locationMap[name] = _totalSize;
    _sizeMap[name] = size;
    _totalSize += size;
}

int RiscvFrame::getSize(const std::string &name) const {
    auto it = _sizeMap.find(name);
    if (it != _sizeMap.end()) {
        return it->second;
    }
    std::cerr << "Error: Variable " << name << " not found in frame." << std::endl;
    exit(EXIT_FAILURE);
    return 0;
}


int RiscvFrame::getOffset(const std::string &name) const {
    auto it = _locationMap.find(name);
    if (it != _locationMap.end()) {
        return it->second;
    }
    std::cerr << "Error: Variable " << name << " not found in frame." << std::endl;
    exit(EXIT_FAILURE);
    return 0;
}


void RiscvFrame::analyzeFunction(const LLVMFunction &func) {
    RA_OFFSET = 0;
    FP_OFFSET = 8;
    _totalSize = 16;
    for (const auto &param : func.parameters) {
        int size = param.type.getArraySize();
        // 4 字节对齐
        size = (size + 3) / 4 * 4;
        addLocal(param.name, size);
    }
    for (const auto &block : func.basicblocks) {
        for (const auto &inst : block->llvm_ins) {
            if (inst.type == LLVM_INS_T::ALLOCA) {
                int size = std::stoi(inst.operands[1]);
                // 4 字节对齐
                size = (size + 3) / 4 * 4;
                std::string name = ssa2riscv(inst.result);
                addLocal(name, size);
            } else if (inst.type == LLVM_INS_T::LOAD) {
                int size = std::stoi(inst.operands[0]);
                size = (size + 3) / 4 * 4;
                std::string name = ssa2riscv(inst.result);
                addLocal(name, size);
            } else if (inst.type == LLVM_INS_T::ADD || inst.type == LLVM_INS_T::SUB || inst.type == LLVM_INS_T::MUL
                || inst.type == LLVM_INS_T::DIV || inst.type == LLVM_INS_T::MOD) {
                int size = 4;
                std::string name = ssa2riscv(inst.result);
                addLocal(name, size);
            } else if (inst.type == LLVM_INS_T::GEP) {
                int size = 8;
                std::string name = ssa2riscv(inst.result);
                addLocal(name, size);
            } else if (inst.type == LLVM_INS_T::BITCAST) {
                int size = 8;
                std::string name = ssa2riscv(inst.result);
                addLocal(name, size);
            } else if (inst.type == LLVM_INS_T::NEQ ||
                inst.type == LLVM_INS_T::EQ ||
                inst.type == LLVM_INS_T::LT ||
                inst.type == LLVM_INS_T::LE ||
                inst.type == LLVM_INS_T::GT ||
                inst.type == LLVM_INS_T::GE) {
                int size = 4;
                std::string name = ssa2riscv(inst.result);
                addLocal(name, size);
            } else if (inst.type == LLVM_INS_T::PHI) {
                if (inst.result == "null") continue;
                int size = 4;
                std::string name = ssa2riscv(inst.result);
                addLocal(name, size);
            } else if (inst.type == LLVM_INS_T::OR ||
                inst.type == LLVM_INS_T::AND) {
                int size = 4;
                std::string name = ssa2riscv(inst.result);
                addLocal(name, size);
            }
        }
    }
}

void RiscvFrame::bitCast(const std::string &src, const std::string &dst) {
    _locationMap[dst] = _locationMap[src];
}