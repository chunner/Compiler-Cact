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

    // 获取变量/寄存器的偏移量
    int getOffset(const std::string& name) const;
    int getSize(const std::string &name) const;

    // 获取总大小，用于生成函数序言
    int getTotalFrameSize() const { return _totalSize; }

    bool hasLocal(const std::string& name) const {
        return _locationMap.find(name) != _locationMap.end();
    }

    // 保存 ra 和 fp 的固定偏移量
    int RA_OFFSET;
    int FP_OFFSET;

    // 分析函数
    void analyzeFunction(const LLVMFunction &func);

    void bitCast(const std::string &src, const std::string &dst);

private:
    int _currentOffset; // 初始偏移量，留出空间给 ra 和 fp
    int _totalSize = 0;
    // 一个 map 统一存储所有东西（局部变量、虚拟寄存器）的偏移量
    std::unordered_map<std::string, int> _locationMap;
    std::unordered_map<std::string, int> _sizeMap;

};


#endif // RISCV_FRAME_H