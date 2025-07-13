#ifndef RISCV_FRAME_H
#define RISCV_FRAME_H

#include <string>
#include <unordered_map>
#include <vector>
#include "IRGenerator.h"

class RiscvFrame {
public:
    // 在分析阶段调用：为 alloca 指令分配栈空间
    void addLocal(const std::string& name, int size);

    // 在分析阶段调用：为 LLVM 虚拟寄存器 (%0, %1...) 分配栈空间
    // 这是我们简化寄存器分配的关键：所有中间值都存到栈上
    void addVirtualRegister(const std::string& name, int size = 4);

    // 获取变量/寄存器的偏移量
    int getOffset(const std::string& name) const;

    // 在分析阶段结束后调用：计算总栈帧大小，考虑对齐
    void calculateFrameSize();

    // 获取总大小，用于生成函数序言
    int getTotalFrameSize() const { return _totalSize; }

    // 保存 ra 和 fp 的固定偏移量
    int RA_OFFSET;
    int FP_OFFSET;

    // 分析函数
    void analyzeFunction(const LLVMFunction &func);

private:
    int _currentOffset; // 初始偏移量，留出空间给 ra 和 fp
    int _totalSize = 0;
    // 一个 map 统一存储所有东西（局部变量、虚拟寄存器）的偏移量
    std::unordered_map<std::string, int> _locationMap;
};


#endif // RISCV_FRAME_H