#include "AST/PType.hpp"
#include <vector>
#include <stack>
#include <string>
#include "AST/ast.hpp"
#include "AST/decl.hpp"

enum class SymbolKind {
    PROGRAM,
    FUNCTION,
    PARAMETER,
    VARIABLE,
    LOOP_VAR,
    CONSTANT,
};

class SymbolEntry {
public:
    SymbolEntry(Location location, const char* name, SymbolKind kind, uint32_t level, 
                PTypeSharedPtr type, std::string attribute);
    ~SymbolEntry() = default;

    const char* getName() const { return name; }
    SymbolKind getKind() const { return kind; }
    int getLevel() const { return level; }
    PTypeSharedPtr getType() const { return type; }
    std::string getAttribute() const { return attribute; }
    Location getLocation() const { return location; }
    bool isInvalidDeclaration() const { return m_isInvalidDeclaration; }
    void setInvalidDeclaration(bool p_is_invalid) { m_isInvalidDeclaration = p_is_invalid; }
    void dump() const;

    void setParameters(const std::vector<std::unique_ptr<DeclNode>> &p_parameters) { 
        m_parameters.clear();
        for (const auto& param : p_parameters) {
            m_parameters.push_back(param.get());  // Store raw pointer, FunctionNode owns the DeclNode
        }
     }
    const std::vector<DeclNode*> &getParameters() const { return m_parameters; }
private:
    Location location;
    const char* name;
    SymbolKind kind;
    int level;
    PTypeSharedPtr type;
    std::string attribute;
    std::vector<DeclNode*> m_parameters;  // Store raw pointers, don't own them

    bool m_isInvalidDeclaration = false;
};

class SymbolTable {
public:
    SymbolTable(uint32_t level) : level(level) {}
    ~SymbolTable() = default;
    void addSymbol(const SymbolEntry& entry);
    uint32_t getLevel() const { return level; }
    SymbolEntry* lookup(const char* name) const;

    void dump() const;
    
private:
    uint32_t level;
    std::vector <SymbolEntry> m_entries;
};

class SymbolManager {
public:
    SymbolManager() = default;

    void pushScope(SymbolTable* new_scope);
    void popScope();

    SymbolEntry* lookup(const char* name);
    void addEntry(Location location, const char* name, SymbolKind kind, PTypeSharedPtr type, std::string attribute);

    void dumpTopSymbolTable() ;
    int getCurrentLevel() const { return m_scopes.back()->getLevel(); }

private:
    std::vector<SymbolTable*> m_scopes;

};