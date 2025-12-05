#include "sema/SymbolTable.hpp"
#include <cstring>

static const char* kind_strings[] = {
    "program",
    "function",
    "parameter",
    "variable",
    "loop_var",
    "constant"
};

void dumpDemarcation(const char chr) {
    for (size_t i = 0; i < 110; ++i) {
      printf("%c", chr);
    }
    puts("");
}

void SymbolManager::pushScope(SymbolTable* scope) {
    m_scopes.push_back(scope);
}

void SymbolManager::popScope() {
    m_scopes.pop_back();
}

void SymbolManager::dumpTopSymbolTable() {
    if (!m_scopes.empty()){
        m_scopes.back()->dump();
    } else {
        printf("No symbol table to dump");
    }
}

SymbolEntry* SymbolManager::lookup(const char* name) { 
    for (int i = m_scopes.size() - 1; i >= 0; i--) {
        SymbolEntry* entry = m_scopes[i]->lookup(name);
        if (entry != nullptr) {
            return entry;
        }
    }
    return nullptr;
}

void SymbolManager::addEntry(Location location, const char* name, SymbolKind kind, PTypeSharedPtr type, std::string attribute) {
    SymbolTable* current_scope = m_scopes.back();

    SymbolEntry new_entry(
        location,
        name,
        kind,
        current_scope->getLevel(),
        type,
        attribute
    );
    current_scope->addSymbol(new_entry);
}


void SymbolTable::addSymbol(const SymbolEntry& entry) {
    m_entries.push_back(entry);
}

SymbolEntry* SymbolTable::lookup(const char* name) const {
    for (auto &entry : m_entries) {
        //printf("entry.getName(): %s, name: %s\n", entry.getName(), name);
        if (strcmp(entry.getName(), name) == 0) {
            return const_cast<SymbolEntry*>(&entry);
        }
    }
    return nullptr;
}

void SymbolTable::dump() const {
    dumpDemarcation('=');
    printf("%-33s%-11s%-11s%-17s%-11s\n", "Name", "Kind", "Level", "Type",
        "Attribute");
    dumpDemarcation('-');
    for (auto entry : m_entries) {
        entry.dump();
    }
    dumpDemarcation('-');
}

// Constructor for SymbolEntry
SymbolEntry::SymbolEntry(Location location, const char* name, SymbolKind kind, uint32_t level, 
                PTypeSharedPtr type, std::string attribute) : location(location), name(name), kind(kind), level(level), type(type), attribute(attribute) {}

void SymbolEntry::dump() const { 
    printf("%-33s", name);
    printf("%-11s", kind_strings[static_cast<size_t>(kind)]);
    printf("%d%-10s", level, level ? "(local)" : "(global)");

    printf("%-17s", type->getPTypeCString());
    // todo: dump the symbol entry
    printf("%-11s", attribute.c_str());
    printf("\n");
}