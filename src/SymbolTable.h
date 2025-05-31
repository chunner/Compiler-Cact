#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <unordered_map>
#include <iostream>
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
    VarType(BaseType baseT)
        : baseType(baseT) {
    };
};

enum class SymbolKind {
    VARIABLE,
    FUNCTION,
    CONSTANT
};

struct Symbol {
    std::string name;
    VarType type;
    std::string ssa;
    Symbol() : name(""), type(BaseType::VOID) {
    };
    Symbol(std::string name, VarType type, std::string ssa)
        : name(std::move(name)), type(std::move(type)), ssa(std::move(ssa)) {
    };
};


class SymbolTable {
public:
    SymbolTable(SymbolTable *parent);
    ~SymbolTable();

    void define(const Symbol &symbol);
    std::pair<Symbol *, bool>lookup(const std::string &name, bool isFunction = false);
    bool lookupInCurrentScope(const std::string &name, bool isFunction = false);
    SymbolTable *getParent();
    bool isGlobal() const {
        return parent == nullptr;
    }

private:
    std::unordered_map<std::string, Symbol> var_table;
    std::unordered_map<std::string, Symbol> func_table;
    SymbolTable *parent;
};

#endif