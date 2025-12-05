#include "AST/ConstantValue.hpp"
#include "AST/PType.hpp"
#include "visitor/AstNodeVisitor.hpp"
#include <string>

// TODO
ConstantValueNode::ConstantValueNode(const uint32_t line, const uint32_t col,
                                     PType *type, int value)
    : ExpressionNode{line, col}, type(type), int_value(value) {}


ConstantValueNode::ConstantValueNode(const uint32_t line, const uint32_t col,
                                     PType *type, float value)
    : ExpressionNode{line, col}, type(type), real_value(value) {}

ConstantValueNode::ConstantValueNode(const uint32_t line, const uint32_t col,
                                     PType *type, bool value)
    : ExpressionNode{line, col}, type(type), bool_value(value) {}

ConstantValueNode::ConstantValueNode(const uint32_t line, const uint32_t col,
                                     PType *type, const char *value)
    : ExpressionNode{line, col}, type(type), string_value(value) {}

// TODO: You may use code snippets in AstDumper.cpp
void ConstantValueNode::print() {}

void ConstantValueNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}

std::string ConstantValueNode::getConstantValueString() const {
    if (type->type == PType::kInteger) {
        return std::to_string(int_value);
    } else if (type->type == PType::kReal) {
        return std::to_string(real_value);
    } else if (type->type == PType::kBoolean) {
        return bool_value ? "true" : "false";
    } else if (type->type == PType::kString) {
        return string_value;
    } else {
        return "";
    }
}

PType *ConstantValueNode::getType() const {
    return type;
}