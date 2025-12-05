#include "AST/assignment.hpp"
#include "visitor/AstNodeVisitor.hpp"

// TODO
AssignmentNode::AssignmentNode(const uint32_t line, const uint32_t col,
                               VariableReferenceNode *variable_reference, ExpressionNode *expression)
    : AstNode{line, col}, variable_reference(variable_reference), expression(expression) {}

// TODO: You may use code snippets in AstDumper.cpp
void AssignmentNode::print() {}

void AssignmentNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    variable_reference->accept(p_visitor);
    expression->accept(p_visitor);
}

void AssignmentNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}