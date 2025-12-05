#ifndef __AST_BINARY_OPERATOR_NODE_H
#define __AST_BINARY_OPERATOR_NODE_H

#include "AST/expression.hpp"
#include "AST/operator.hpp"
#include <memory>

class BinaryOperatorNode : public ExpressionNode {
  public:
    BinaryOperatorNode(const uint32_t line, const uint32_t col,
                       OperatorNode *p_operator, ExpressionNode *p_left, ExpressionNode *p_right);
    ~BinaryOperatorNode() = default;

    void print() override;
    void visitChildNodes(AstNodeVisitor &p_visitor) override;
    void accept(AstNodeVisitor &p_visitor) override;

    std::string getOperatorString();

  private:
    OperatorNode *m_operator;
    ExpressionNode *m_left;
    ExpressionNode *m_right;
};

#endif
