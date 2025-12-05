#include "AST/decl.hpp"
#include "visitor/AstNodeVisitor.hpp"

// TODO
DeclNode::DeclNode(const uint32_t line, const uint32_t col,
                   std::vector <VariableNode *> *p_variables)
    : AstNode{line, col}, variables(*p_variables) {}

// TODO 
//DeclNode::DeclNode(const uint32_t line, const uint32_t col)
//    : AstNode{line, col} {}

// TODO: You may use code snippets in AstDumper.cpp
void DeclNode::print() {}

void DeclNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    for (auto &variable : variables) {
        variable->accept(p_visitor);
    }
}

void DeclNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}

const std::vector <VariableNode *> *DeclNode::getVariables() const {
    return &variables;
}