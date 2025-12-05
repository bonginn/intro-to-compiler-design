#include "AST/BinaryOperator.hpp"
#include "visitor/AstNodeVisitor.hpp"

// TODO
BinaryOperatorNode::BinaryOperatorNode(const uint32_t line, const uint32_t col,
                                       OperatorNode *p_operator, ExpressionNode *p_left, ExpressionNode *p_right)
    : ExpressionNode{line, col}, m_operator(p_operator), m_left(p_left), m_right(p_right) {}

// TODO: You may use code snippets in AstDumper.cpp
void BinaryOperatorNode::print() {}

void BinaryOperatorNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    m_left->accept(p_visitor);
    m_right->accept(p_visitor);
}

void BinaryOperatorNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}

std::string BinaryOperatorNode::getOperatorString() {
    return m_operator->getOperatorString();
}

