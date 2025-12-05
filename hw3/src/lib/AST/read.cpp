#include "AST/read.hpp"
#include "visitor/AstNodeVisitor.hpp"

// TODO
ReadNode::ReadNode(const uint32_t line, const uint32_t col,
                   VariableReferenceNode *variable_reference)
    : AstNode{line, col}, variable_reference(variable_reference) {}

// TODO: You may use code snippets in AstDumper.cpp
void ReadNode::print() {}

void ReadNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    variable_reference->accept(p_visitor);
}

void ReadNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}
