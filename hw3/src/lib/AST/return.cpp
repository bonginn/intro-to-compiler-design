#include "AST/return.hpp"
#include "visitor/AstNodeVisitor.hpp"

// TODO
ReturnNode::ReturnNode(const uint32_t line, const uint32_t col,
                       ExpressionNode *expression)
    : AstNode{line, col}, expression(expression) {}

// TODO: You may use code snippets in AstDumper.cpp
void ReturnNode::print() {}

void ReturnNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    expression->accept(p_visitor);
}

void ReturnNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}