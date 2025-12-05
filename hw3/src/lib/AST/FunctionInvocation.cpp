#include "AST/FunctionInvocation.hpp"
#include <cstdio>

// TODO
FunctionInvocationNode::FunctionInvocationNode(const uint32_t line,
                                               const uint32_t col,
                                               const char *name,
                                               std::vector <ExpressionNode*> *arguments)
    : ExpressionNode{line, col}, name(name), arguments(arguments) {}

// TODO: You may use code snippets in AstDumper.cpp
void FunctionInvocationNode::print() {}

void FunctionInvocationNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    //printf("arguments size: %lu\n", arguments->size());
    for(auto &argument : *arguments) {
        argument->accept(p_visitor);
    }
}

const char *FunctionInvocationNode::getNameCString() const {
    return name;
}