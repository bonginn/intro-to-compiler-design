#ifndef AST_OPERATOR_HPP
#define AST_OPERATOR_HPP

#include <cstdint>
#include <string>

class OperatorNode {
    public:
        enum OperatorType {
            UNARY_MINUS,
            MULTIPLY,
            DIVIDE,
            MOD,
            PLUS,
            MINUS,
            LESS,
            LESS_OR_EQUAL,
            GREATER,
            GREATER_OR_EQUAL,
            EQUAL,
            NOT_EQUAL,
            AND,
            OR,
            NOT
        };

        OperatorNode(OperatorType op);
        ~OperatorNode() = default;

        void print();
        std::string getOperatorString();

    private:
        OperatorType op;
        std::string op_string;
        void setOperatorString(OperatorType op);
};

#endif  // AST_OPERATOR_HPP