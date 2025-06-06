#ifndef TYPES_H
#define TYPES_H

#include <string>
#include <vector>

enum class BaseType {
    I1,
    I8,
    I32,
    FLOAT,
    DOUBLE,
    VOID
};


struct VarType {
    BaseType baseType;
    bool isConst = false;
    bool isFunction = false;

    std::vector<int> dimSizes; // baseType ID [dimSizes[n]] [dimSizes[n-1]] ... [dimSizes[0]]
    bool isArray() const {
        return !dimSizes.empty();
    }
    int getArraySize() const;
    VarType(BaseType baseT, bool isConst, bool isFunction, std::vector<int> dimSizes)
        : baseType(baseT), isConst(isConst), isFunction(isFunction), dimSizes(std::move(dimSizes)) {
    };
    VarType(BaseType baseT, bool isConst, bool isFunction)
        : baseType(baseT), isConst(isConst), isFunction(isFunction) {
    };
    VarType(BaseType baseT, bool isConst)
        : baseType(baseT), isConst(isConst), isFunction(false) {
    };
    VarType(BaseType baseT)
        : baseType(baseT) {
    };
};

struct LLVMValue {
    std::string name;
    VarType type;

    LLVMValue(std::string name, VarType type) : name(name), type(type) {}
};


#endif