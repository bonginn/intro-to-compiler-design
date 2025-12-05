#ifndef AST_PROGRAM_NODE_H
#define AST_PROGRAM_NODE_H

#include "AST/ast.hpp"
#include "AST/CompoundStatement.hpp"
#include "AST/decl.hpp"
#include "AST/function.hpp"

#include <memory>
#include <string>
#include <vector>

class ProgramNode final : public AstNode {
  private:
    std::string name;
    std::vector <DeclNode *> *m_declarations;
    std::vector <FunctionNode *> *m_functions;
    CompoundStatementNode *m_body;

  public:
    ~ProgramNode() = default;
    ProgramNode(const uint32_t line, const uint32_t col,
                const char *const p_name, 
                std::vector <DeclNode *> *const p_declarations,
                std::vector <FunctionNode *> *const p_functions,
                CompoundStatementNode *const p_body
                /* TODO: return type, declarations, functions,
                 *       compound statement */);

    // visitor pattern version: const char *getNameCString() const;
    void print() override;
    const char *getNameCString() const { return name.c_str(); }
    void accept(AstNodeVisitor &p_visitor) override;
    void visitChildNodes(AstNodeVisitor &p_visitor) override;
};

#endif
