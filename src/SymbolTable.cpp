#include "SymbolTable.h"

int VarType::getArraySize()const {
    int size;
    switch (baseType) {
        case BaseType::I32:
            size = 4; 
            break;
        case BaseType::I8:
            size = 1; 
            break;
        case BaseType::FLOAT:
            size = 4; // assuming 4 bytes for float
            break;
        default:
            std::cerr << "Error: Unsupported base type for array size calculation!" << std::endl;
            exit(EXIT_FAILURE);
    }
    for (int dim : dimSizes) {
        size *= dim;
    }
    return size;
}






SymbolTable::SymbolTable(SymbolTable *parent) :parent(parent) {
}

SymbolTable::~SymbolTable() {
    // Destructor implementation
}

void SymbolTable::define(const Symbol &symbol) {
    if (symbol.type.isFunction) {
        func_table[symbol.name] = symbol;
    } else {
        var_table[symbol.name] = symbol;
    }
}


std::pair<Symbol *, bool> SymbolTable::lookup(const std::string &name, bool isFunction) {
    if (isFunction) {
        if (func_table.find(name) != func_table.end()) {
            return std::make_pair(&func_table[name], isGlobal());
        } else {
            if (parent) {
                return parent->lookup(name, isFunction);
            } else {
                return std::make_pair(nullptr, false);
            }
        }
    } else {
        if (var_table.find(name) != var_table.end()) {
            return std::make_pair(&var_table[name], isGlobal());
        } else {
            if (parent) {
                return parent->lookup(name, isFunction);
            } else {
                return std::make_pair(nullptr, false);
            }
        }
    }
}

bool SymbolTable::lookupInCurrentScope(const std::string &name, bool isFunction) {
    if (isFunction) {
        return func_table.find(name) != func_table.end();
    } else {
        return var_table.find(name) != var_table.end();
    }
}

SymbolTable *SymbolTable::getParent() {
    return parent;
}