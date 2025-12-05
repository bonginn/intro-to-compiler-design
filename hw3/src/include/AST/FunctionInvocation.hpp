#ifndef __AST_FUNCTION_INVOCATION_NODE_H
#define __AST_FUNCTION_INVOCATION_NODE_H

#include "AST/expression.hpp"
#include <vector>
#include "visitor/AstNodeVisitor.hpp"

class FunctionInvocationNode : public ExpressionNode {
  public:
    FunctionInvocationNode(const uint32_t line, const uint32_t col,
                           const char *name, std::vector <ExpressionNode*> *arguments);
    ~FunctionInvocationNode() = default;

    const char *getNameCString() const;

    void print() override;
    void visitChildNodes(AstNodeVisitor &p_visitor) override;
    void accept(AstNodeVisitor &p_visitor) override { p_visitor.visit(*this); }

  private:
    const char *name;
    std::vector <ExpressionNode*> *arguments;
};

#endif
