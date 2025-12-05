#include "AST/UnaryOperator.hpp"
#include "visitor/AstNodeVisitor.hpp"

// TODO
UnaryOperatorNode::UnaryOperatorNode(const uint32_t line, const uint32_t col,
                                     OperatorNode *p_operator, ExpressionNode *p_operand)
    : ExpressionNode{line, col}, m_operator(p_operator), m_operand(p_operand) {}

// TODO: You may use code snippets in AstDumper.cpp
void UnaryOperatorNode::print() {}

void UnaryOperatorNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    m_operand->accept(p_visitor);
}

void UnaryOperatorNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}

std::string UnaryOperatorNode::getOperatorString() {
    return m_operator->getOperatorString();
}

