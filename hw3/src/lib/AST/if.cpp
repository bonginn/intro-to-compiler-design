#include "AST/if.hpp"
#include "visitor/AstNodeVisitor.hpp"

// TODO
IfNode::IfNode(const uint32_t line, const uint32_t col,
               ExpressionNode *expression, CompoundStatementNode *body, CompoundStatementNode *else_body)
    : AstNode{line, col}, expression(expression), body(body), else_body(else_body) {}

// TODO: You may use code snippets in AstDumper.cpp
void IfNode::print() {}

void IfNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    expression->accept(p_visitor);
    body->accept(p_visitor);
    if (else_body != nullptr) {
        else_body->accept(p_visitor);
    }
}

void IfNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}