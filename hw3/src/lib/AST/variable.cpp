#include "AST/variable.hpp"
#include "visitor/AstNodeVisitor.hpp"

// TODO
VariableNode::VariableNode(const uint32_t line, const uint32_t col, char *name)
    : AstNode{line, col}, name(name) {}

// TODO: You may use code snippets in AstDumper.cpp
void VariableNode::print() {}

void VariableNode::setType(PType *p) {
    type = p;
}

void VariableNode::setConstant(ConstantValueNode *p) {
    constantValue = p;
}

PType *VariableNode::getType() {
    return type;
}

const char *VariableNode::getNameCString() {
    return name.c_str();
}

std::string VariableNode::getTypeString() {
    if (type == nullptr) { // This var is a constant
        return constantValue->getType()->getTypeString();
    }
    return type->getTypeString();
}

void VariableNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    if (constantValue != nullptr) {
        constantValue->accept(p_visitor);
    }

}

void VariableNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}