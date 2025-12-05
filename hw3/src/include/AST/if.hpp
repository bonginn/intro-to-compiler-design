#ifndef __AST_IF_NODE_H
#define __AST_IF_NODE_H

#include "AST/ast.hpp"
#include "AST/expression.hpp"
#include "AST/CompoundStatement.hpp"


class IfNode : public AstNode {
  public:
    IfNode(const uint32_t line, const uint32_t col,
           ExpressionNode *expression, CompoundStatementNode *body, CompoundStatementNode *else_body);
    ~IfNode() = default;

    void print() override;
    void visitChildNodes(AstNodeVisitor &p_visitor) override;
    void accept(AstNodeVisitor &p_visitor) override;

  private:
    ExpressionNode *expression;
    CompoundStatementNode *body;
    CompoundStatementNode *else_body = nullptr;
};

#endif
