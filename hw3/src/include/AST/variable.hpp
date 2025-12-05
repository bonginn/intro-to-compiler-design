#ifndef __AST_VARIABLE_NODE_H
#define __AST_VARIABLE_NODE_H

#include "AST/ast.hpp"  
#include "AST/PType.hpp"
#include "AST/ConstantValue.hpp"
#include <string>

class VariableNode : public AstNode {
  public:
    VariableNode(const uint32_t line, const uint32_t col, char *name);
    ~VariableNode() = default;

    void print() override;
    void visitChildNodes(AstNodeVisitor &p_visitor) override;
    void accept(AstNodeVisitor &p_visitor) override;

    void setType(PType *p);
    const char *getNameCString();
    PType *getType();
    void setConstant(ConstantValueNode *p); 
    std::string getTypeString();

  private:
    std::string name;
    PType *type = nullptr;
    ConstantValueNode *constantValue = nullptr;
    // TODO: variable name, type, constant value
};

#endif
