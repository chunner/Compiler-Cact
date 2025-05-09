#include "SymbolTable.h"

SymbolTable::SymbolTable(SymbolTable *parent) :parent(parent) {
}

SymbolTable::~SymbolTable() {
    // Destructor implementation
}

void SymbolTable::define(const Symbol &symbol) {
    // Check if the symbol already exists in current scope
    if (lookupInCurrentScope(symbol.name)) {
        std::cerr << "Error: Symbol '" << symbol.name << "' already defined in current scope." << std::endl;
    } else {
        table[symbol.name] = symbol;
    }
}

Symbol *SymbolTable::lookup(const std::string &name) {
    // Check current scope
    if (lookupInCurrentScope(name)) {
        return &table[name];
    } else if(parent != nullptr){
        return parent->lookup(name);
    }
    return nullptr;
}

bool SymbolTable::lookupInCurrentScope(const std::string &name) {
    return table.find(name) != table.end();
}

SymbolTable *SymbolTable::getParent() {
    return parent;
}