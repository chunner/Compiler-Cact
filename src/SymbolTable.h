#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

enum class BaseType {
    INT,
    DOUBLE,
    CHAR,
    FLOAT,
    VOID    // for function
};
struct VarType {
    BaseType baseType;
    bool isConst = false;
    bool isFunction = false;

    std::vector<int> dimSizes; // baseType ID [dimSizes[n]] [dimSizes[n-1]] ... [dimSizes[0]]
    bool isArray() const {
        return !dimSizes.empty();
    }
};

enum class SymbolKind {
    VARIABLE,
    FUNCTION,
    CONSTANT
};

struct Symbol {
    std::string name;
    VarType type;
};


class SymbolTable {
public:
    SymbolTable(SymbolTable *parent);
    ~SymbolTable();

    void define(const Symbol &symbol);
    Symbol *lookup(const std::string &name);
    bool lookupInCurrentScope(const std::string &name);
    SymbolTable *getParent();

private:
    std::unordered_map<std::string, Symbol> table;
    SymbolTable *parent;
};

#endif