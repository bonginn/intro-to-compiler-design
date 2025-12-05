#include "AST/program.hpp"
#include "visitor/AstNodeVisitor.hpp"

// TODO
ProgramNode::ProgramNode(const uint32_t line, const uint32_t col,
                         const char *const p_name, std::vector <DeclNode *> *p_declarations,
                         std::vector <FunctionNode *> *p_functions,
                         CompoundStatementNode *const p_body)
    : AstNode{line, col}, name(p_name), m_declarations(p_declarations), m_functions(p_functions), m_body(p_body) {}

// visitor pattern version: const char *ProgramNode::getNameCString() const { return name.c_str(); }

void ProgramNode::print() { 
    // TODO
    // outputIndentationSpace();

    std::printf("program <line: %u, col: %u> %s %s\n",
                location.line, location.col,
                name.c_str(), "void");

    // TODO
    // incrementIndentation();
    // visitChildNodes();
    // decrementIndentation();
}


void ProgramNode::visitChildNodes(AstNodeVisitor &p_visitor) { // visitor pattern version
    for (auto &decl : *m_declarations) {
        decl->accept(p_visitor);
    }
    for (auto &func : *m_functions) {
        func->accept(p_visitor);
    }
    m_body->accept(p_visitor);
}

void ProgramNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}