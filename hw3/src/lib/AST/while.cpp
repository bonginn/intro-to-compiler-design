#include "AST/while.hpp"
#include "visitor/AstNodeVisitor.hpp"

// TODO
WhileNode::WhileNode(const uint32_t line, const uint32_t col,
                    ExpressionNode *expression, CompoundStatementNode *body)
    : AstNode{line, col}, expression(expression), body(body) {}

// TODO: You may use code snippets in AstDumper.cpp
void WhileNode::print() {}

void WhileNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    expression->accept(p_visitor);
    body->accept(p_visitor);
}

void WhileNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}
