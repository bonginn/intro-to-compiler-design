#include "AST/function.hpp"
#include "visitor/AstNodeVisitor.hpp"

// TODO
FunctionNode::FunctionNode(const uint32_t line, const uint32_t col,
                char *name, 
                std::vector <DeclNode *> *declarations,
                PType *returnType, 
                CompoundStatementNode *compoundStatement)
    : AstNode{line, col}, name(name), declarations(declarations), returnType(returnType), compoundStatement(compoundStatement) {}

// TODO: You may use code snippets in AstDumper.cpp
void FunctionNode::print() {}

void FunctionNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    for (auto &declaration : *declarations) {
        declaration->accept(p_visitor);
    }
    if (compoundStatement != nullptr) {
        compoundStatement->accept(p_visitor);
    }
}

void FunctionNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}

const char *FunctionNode::getNameCString() const {
    return name;
}

std::string FunctionNode::getPrototypeString() {
    std::string prototype;
    if (returnType != nullptr) {
        prototype = returnType->getTypeString();
    }
    else {
        prototype = "void";
    }
    prototype += " (";
    std::vector <std::string> typeStringBag;
    std::string typeString = "";
    bool isFirst = true;
    for (auto &declaration : *declarations) {
        for (auto &variable : *declaration->getVariables()) {
            if (isFirst) {
                typeString += variable->getTypeString();
                isFirst = false;
            }
            else {
                typeString += ", " + variable->getTypeString();
            }
        }
    }
    prototype += typeString + ")";
    return prototype;
}
