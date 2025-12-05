#ifndef __AST_DECL_NODE_H
#define __AST_DECL_NODE_H

#include "AST/ast.hpp"
#include "AST/variable.hpp"
#include <vector>
#include <memory>


class DeclNode : public AstNode {
  public:
    // variable declaration
    DeclNode(const uint32_t line, const uint32_t col,
             std::vector <VariableNode *> *p_variables);

    ~DeclNode() = default;

    void print() override;
    void visitChildNodes(AstNodeVisitor &p_visitor) override;
    void accept(AstNodeVisitor &p_visitor) override;

    const std::vector <VariableNode *> *getVariables() const;

  private:
    std::vector <VariableNode *> variables;
    // TODO: variables
};

#endif
