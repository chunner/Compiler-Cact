#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <unordered_map>
#include <iostream>

enum class ValueType {
    INT,
    DOUBLE,
    CHAR,
    FLOAT,
    VOID
};
enum class SymbolKind {
    VARIABLE,
    FUNCTION,
    CONSTANT
};
struct Symbol {
    std::string name;
    ValueType type;
    SymbolKind kind;
    bool isArray = false;
    int arraySize = 0;
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