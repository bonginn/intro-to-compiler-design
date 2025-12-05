#include "AST/operator.hpp"

OperatorNode::OperatorNode(OperatorType op)
    : op(op) {
        setOperatorString(op);
    }

void OperatorNode::setOperatorString(OperatorType op) {
    switch (op) {
        case UNARY_MINUS:
            op_string = "neg";
            break;
        case MULTIPLY:
            op_string = "*";
            break;
        case DIVIDE:
            op_string = "/";
            break;
        case MOD:
            op_string = "mod";
            break;
        case PLUS:
            op_string = "+";
            break;
        case MINUS:
            op_string = "-";
            break;
        case LESS:
            op_string = "<";
            break;
        case LESS_OR_EQUAL:
            op_string = "<=";
            break;
        case GREATER:
            op_string = ">";
            break;
        case GREATER_OR_EQUAL:
            op_string = ">=";
            break;
        case EQUAL:
            op_string = "=";
            break;
        case NOT_EQUAL:
            op_string = "<>";
            break;
        case AND:
            op_string = "and";
            break;
        case OR:
            op_string = "or";
            break;
        case NOT:
            op_string = "not";
            break;
        default:
            op_string = "unknown";
            break;
    }
}

std::string OperatorNode::getOperatorString() {
    return op_string;
}
