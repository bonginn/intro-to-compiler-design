#ifndef __AST_CONSTANT_VALUE_NODE_H
#define __AST_CONSTANT_VALUE_NODE_H

#include "AST/expression.hpp"
#include "AST/PType.hpp"
#include <string>

class ConstantValueNode : public ExpressionNode {
  public:
    enum ConstantType {
        kInteger,
        kReal,
        kBoolean,
        kString
    };

    ConstantValueNode(const uint32_t line, const uint32_t col,
                      PType *type, int value); // int constant  
    ConstantValueNode(const uint32_t line, const uint32_t col,
                      PType *type, float value);  // float constant
    ConstantValueNode(const uint32_t line, const uint32_t col,
                      PType *type, bool value);  // boolean constant
    ConstantValueNode(const uint32_t line, const uint32_t col,
                      PType *type, const char *value);  // string constant
    
    ~ConstantValueNode() = default;


    void print() override;
    void accept(AstNodeVisitor &p_visitor) override;
    void visitChildNodes(AstNodeVisitor &p_visitor) override {
        // No child nodes
    };
    std::string getConstantValueString() const;
    PType *getType() const;

  private:
      PType *type;
      int int_value;
      float real_value;
      bool bool_value;
      const char *string_value;
    // TODO: constant value
};

#endif
