#ifndef __AST_VARIABLE_REFERENCE_NODE_H
#define __AST_VARIABLE_REFERENCE_NODE_H

#include "AST/expression.hpp"
#include <vector>

class VariableReferenceNode : public ExpressionNode {
  public:
    // normal reference
    VariableReferenceNode(const uint32_t line, const uint32_t col,
                          const char *name, std::vector <ExpressionNode*> *expressions);
    // array reference
    // VariableReferenceNode(const uint32_t line, const uint32_t col
    //                       /* TODO: name, expressions */);
    ~VariableReferenceNode() = default;

    void print() override;
    void visitChildNodes(AstNodeVisitor &p_visitor) override;
    void accept(AstNodeVisitor &p_visitor) override ;

    const char *getNameCString();

  private:
    const char *name;
    std::vector <ExpressionNode*> *expressions;
};

#endif
