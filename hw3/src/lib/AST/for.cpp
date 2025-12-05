#include "AST/for.hpp"
#include "visitor/AstNodeVisitor.hpp"

// TODO
ForNode::ForNode(const uint32_t line, const uint32_t col,
                 DeclNode *declaration, AssignmentNode *assignment, ConstantValueNode *expression, CompoundStatementNode *body)
    : AstNode{line, col}, declaration(declaration), assignment(assignment), expression(expression), body(body) {}

// TODO: You may use code snippets in AstDumper.cpp
void ForNode::print() {}

void ForNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    declaration->accept(p_visitor);
    assignment->accept(p_visitor);
    expression->accept(p_visitor);
    body->accept(p_visitor);
}

void ForNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}