#ifndef SEMA_SEMANTIC_ANALYZER_H
#define SEMA_SEMANTIC_ANALYZER_H

#include "sema/ErrorPrinter.hpp"
#include "sema/Error.hpp"
#include "visitor/AstNodeVisitor.hpp"
#include "sema/SymbolTable.hpp"
#include <memory>
#include <vector>


class ErrorMessage : public Error {
  public:
    ErrorMessage(Location p_location, std::string p_message) : Error(p_location), m_message(p_message) {}
    ~ErrorMessage() = default;
    std::string getMessage() const override { return m_message; }
  private:
    std::string m_message;
};

class SemanticAnalyzer final : public AstNodeVisitor {
  private:
    ErrorPrinter m_error_printer{stderr};
    // TODO: something like symbol manager (manage symbol tables)
    //       context manager, return type manager
    SymbolManager m_symbol_manager;

    SymbolKind m_current_kind = SymbolKind::PROGRAM;
    std::string m_current_attribute = "";
    bool m_just_entered_function_scope = false;
    std::vector<std::unique_ptr<ErrorMessage>> m_error_messages;
    std::stack<PTypeSharedPtr> m_return_type_stack;


  public:
    bool hasError() const { return !m_error_messages.empty(); }
    void dumpErrors() const {
        for (const auto& error : m_error_messages) {
            m_error_printer.print(*error);
        }
    }
    ~SemanticAnalyzer() = default;
    SemanticAnalyzer() = default;

    static bool dump_symbol_table;

    void visit(ProgramNode &p_program) override;
    void visit(DeclNode &p_decl) override;
    void visit(VariableNode &p_variable) override;
    void visit(ConstantValueNode &p_constant_value) override;
    void visit(FunctionNode &p_function) override;
    void visit(CompoundStatementNode &p_compound_statement) override;
    void visit(PrintNode &p_print) override;
    void visit(BinaryOperatorNode &p_bin_op) override;
    void visit(UnaryOperatorNode &p_un_op) override;
    void visit(FunctionInvocationNode &p_func_invocation) override;
    void visit(VariableReferenceNode &p_variable_ref) override;
    void visit(AssignmentNode &p_assignment) override;
    void visit(ReadNode &p_read) override;
    void visit(IfNode &p_if) override;
    void visit(WhileNode &p_while) override;
    void visit(ForNode &p_for) override;
    void visit(ReturnNode &p_return) override;
};

#endif
