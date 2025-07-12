#ifndef RISCV_FRAME_H
#define RISCV_FRAME_H

#include <string>
#include <unordered_map>
#include <vector>

class RiscvFrame {
public:
    void addLocal(const std::string& name); // 为局部变量分配空间
    int getLocalOffset(const std::string& name) const;
    void addParam(const std::string& name); // 为参数分配空间
    int getParamOffset(const std::string& name) const;
    int getFrameSize() const;
    void calculateFrameSize(); // 在所有变量添加后计算总大小

private:
    int _currentOffset = 0; // 从fp开始的负向偏移
    std::unordered_map<std::string, int> _locals;
    std::unordered_map<std::string, int> _params;
    // ... 可能还需要保存寄存器的空间等
};


#endif // RISCV_FRAME_H