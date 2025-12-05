#include "AST/CompoundStatement.hpp"
#include "visitor/AstNodeVisitor.hpp"
#include <vector>

// TODO
CompoundStatementNode::CompoundStatementNode(const uint32_t line,
                                             const uint32_t col, 
                                             std::vector <DeclNode*> *declarations,
                                             std::vector <AstNode*> *statements)
    : AstNode{line, col}, declarations(declarations), statements(statements) {}

// TODO: You may use code snippets in AstDumper.cpp
void CompoundStatementNode::print() {}

void CompoundStatementNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    for(auto &declaration : *declarations) {
        declaration->accept(p_visitor);
    }
    for(auto &statement : *statements) {
        statement->accept(p_visitor);
    }
}

void CompoundStatementNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}
