#ifndef __AST_FUNCTION_NODE_H
#define __AST_FUNCTION_NODE_H

#include "AST/ast.hpp"
#include "AST/decl.hpp"
#include "AST/PType.hpp"
#include "AST/CompoundStatement.hpp"
#include <vector>

class FunctionNode : public AstNode {
  public:
    FunctionNode(const uint32_t line, const uint32_t col,
                char *name, 
                std::vector <DeclNode *> *declarations,
                PType *returnType, 
                CompoundStatementNode *compoundStatement);
    ~FunctionNode() = default;

    void print() override;
    void visitChildNodes(AstNodeVisitor &p_visitor) override;
    void accept(AstNodeVisitor &p_visitor) override;
    const char *getNameCString() const;
    std::string getPrototypeString();

  private:
      char *name;
      std::vector <DeclNode *> *declarations;
      PType *returnType;
      CompoundStatementNode *compoundStatement;
};

#endif
