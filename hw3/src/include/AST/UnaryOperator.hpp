#ifndef __AST_UNARY_OPERATOR_NODE_H
#define __AST_UNARY_OPERATOR_NODE_H

#include "AST/expression.hpp"
#include "AST/operator.hpp"

class UnaryOperatorNode : public ExpressionNode {
  public:
    UnaryOperatorNode(const uint32_t line, const uint32_t col,
                      OperatorNode *p_operator, ExpressionNode *p_operand);
    ~UnaryOperatorNode() = default;

    void print() override;
    void visitChildNodes(AstNodeVisitor &p_visitor) override;
    void accept(AstNodeVisitor &p_visitor) override;

    std::string getOperatorString();

  private:
    OperatorNode *m_operator;
    ExpressionNode *m_operand;
};

#endif
