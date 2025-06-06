#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include "Types.h"



enum class SymbolKind {
    VARIABLE,
    FUNCTION,
    CONSTANT
};

struct Symbol {
    std::string name;
    VarType type;
    std::string ssa;
    std::string constvalue;
    std::vector<LLVMValue> params;
    Symbol() : name(""), type(BaseType::VOID) {
    };
    Symbol(std::string name, VarType type, std::string ssa)
        : name(std::move(name)), type(std::move(type)), ssa(std::move(ssa)) {
    };
    Symbol(std::string name, VarType type, std::string ssa, std::string constvalue)
        : name(std::move(name)), type(std::move(type)), ssa(std::move(ssa)), constvalue(std::move(constvalue)) {
    };
    Symbol(std::string name, VarType type, std::string ssa, std::vector<LLVMValue> params)
        : name(std::move(name)), type(std::move(type)), ssa(std::move(ssa)), params(std::move(params)) {
    };
};


class SymbolTable {
public:
    SymbolTable(SymbolTable *parent);
    ~SymbolTable();

    void define(const Symbol &symbol);
    Symbol *lookup(const std::string &name, bool isFunction = false);
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