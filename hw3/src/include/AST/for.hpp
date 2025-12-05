#ifndef __AST_FOR_NODE_H
#define __AST_FOR_NODE_H

#include "AST/ast.hpp"
#include "AST/decl.hpp"
#include "AST/assignment.hpp"
#include "AST/ConstantValue.hpp"
#include "AST/CompoundStatement.hpp"

class ForNode : public AstNode {
  public:
    ForNode(const uint32_t line, const uint32_t col,
            DeclNode *declaration, AssignmentNode *assignment, ConstantValueNode *expression, CompoundStatementNode *body);
    ~ForNode() = default;

    void print() override;
    void visitChildNodes(AstNodeVisitor &p_visitor) override;
    void accept(AstNodeVisitor &p_visitor) override;

  private:
    DeclNode *declaration;
    AssignmentNode *assignment;
    ConstantValueNode *expression;
    CompoundStatementNode *body;
};

#endif
