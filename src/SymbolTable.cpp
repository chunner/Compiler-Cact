#include "SymbolTable.h"

SymbolTable::SymbolTable(SymbolTable *parent) :parent(parent) {
}

SymbolTable::~SymbolTable() {
    // Destructor implementation
}

void SymbolTable::define(const Symbol &symbol) {
    // Check if the symbol already exists in current scope

}

Symbol *SymbolTable::lookup(const std::string &name, bool isFunction) {
    if (isFunction) {
        if (func_table.find(name) != func_table.end()) {
            return &func_table[name];
        } else {
            if (parent) {
                return parent->lookup(name, isFunction);
            } else {
                return nullptr;
            }
        }
    } else {
        if (var_table.find(name) != var_table.end()) {
            return &var_table[name];
        } else {
            if (parent) {
                return parent->lookup(name, isFunction);
            } else {
                return nullptr;
            }
        }
    }
}

bool SymbolTable::lookupInCurrentScope(const std::string &name,bool isFunction) {
    if (isFunction) {
        return func_table.find(name) != func_table.end();
    } else {
        return var_table.find(name) != var_table.end();
    }
}

SymbolTable *SymbolTable::getParent() {
    return parent;
}