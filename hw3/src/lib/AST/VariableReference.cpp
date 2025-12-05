#include "AST/VariableReference.hpp"
#include "visitor/AstNodeVisitor.hpp"


// TODO
VariableReferenceNode::VariableReferenceNode(const uint32_t line,
                                             const uint32_t col,
                                             const char *name,
                                             std::vector <ExpressionNode*> *expressions)
    : ExpressionNode{line, col}, name(name), expressions(expressions) {}

// TODO
// VariableReferenceNode::VariableReferenceNode(const uint32_t line,
//                                              const uint32_t col)
//     : ExpressionNode{line, col} {}

// TODO: You may use code snippets in AstDumper.cpp
void VariableReferenceNode::print() {}

void VariableReferenceNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    for (auto &expression : *expressions) {
        expression->accept(p_visitor);
    }
}

void VariableReferenceNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}

const char *VariableReferenceNode::getNameCString() {
    return name;
}