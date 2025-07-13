#include "RiscvFrame.h"
#include <iostream>
void RiscvFrame::addLocal(const std::string& name, int size) {
    // 假设所有局部变量都是4字节对齐
    _currentOffset -= size;
    _locationMap[name] = _currentOffset;
}

void RiscvFrame::addVirtualRegister(const std::string& name, int size) {
    if (_locationMap.find(name) == _locationMap.end()) {
        _currentOffset -= size;
        _locationMap[name] = _currentOffset;
    }
}

int RiscvFrame::getOffset(const std::string& name) const {
    auto it = _locationMap.find(name);
    if (it != _locationMap.end()) {
        return it->second;
    }
    std::cerr << "Error: Variable " << name << " not found in frame." << std::endl;
    exit(EXIT_FAILURE);
    return 0;
}

void RiscvFrame::calculateFrameSize() {
    // _currentOffset 是负数，其绝对值就是变量占用的空间
    // 加上保存 ra 和 fp 的 16 字节
    int size = -_currentOffset;
    // 栈帧大小必须是 16 字节对齐
    _totalSize = (size + 15) / 16 * 16;
}