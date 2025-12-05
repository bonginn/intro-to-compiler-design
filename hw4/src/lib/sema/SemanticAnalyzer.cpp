#include "sema/Error.hpp"
#include "sema/SemanticAnalyzer.hpp"
#include "visitor/AstNodeInclude.hpp"

bool SemanticAnalyzer::dump_symbol_table = true;

void SemanticAnalyzer::visit(ProgramNode &p_program) {
    /*
     * TODO:
     *
     * 1. Push a new symbol table if this node forms a scope. yes
     * 2. Insert the symbol into current symbol table if this node is related to
     *    declaration (ProgramNode, VariableNode, FunctionNode). no
     * 3. Traverse child nodes of this node.
     * 4. Perform semantic analyses of this node.
     * 5. Pop the symbol table pushed at the 1st step.
     */
    
    SymbolTable* new_scope = new SymbolTable(0); // program node forms a scope

    // Create a SymbolEntry for the program node
    const char* program_name = p_program.getNameCString();
    SymbolKind program_kind = SymbolKind::PROGRAM;
    uint32_t program_level = 0;
    PTypeSharedPtr program_type = std::make_shared<PType>(PType::PrimitiveTypeEnum::kVoidType); // program type is void
    std::string program_attribute = ""; // program has no attribute
    SymbolEntry program_entry(
        p_program.getLocation(),
        program_name, 
        program_kind, 
        program_level, 
        program_type, 
        program_attribute
    );

    // Add the SymbolEntry to the symbol table
    new_scope->addSymbol(program_entry);
    m_symbol_manager.pushScope(new_scope);

    m_return_type_stack.push(program_type);
    p_program.visitChildNodes(*this);
    // and somthing...

    if (dump_symbol_table) {
        m_symbol_manager.dumpTopSymbolTable();
    }
    m_symbol_manager.popScope();
    m_return_type_stack.pop();
}

void SemanticAnalyzer::visit(DeclNode &p_decl) {
    p_decl.visitChildNodes(*this);
}

void SemanticAnalyzer::visit(VariableNode &p_variable) {
    /*
     * TODO:
     *
     * 1. Push a new symbol table if this node forms a scope.
     * 2. Insert the symbol into current symbol table if this node is related to
     *    declaration (ProgramNode, VariableNode, FunctionNode).
     * 3. Traverse child nodes of this node.
     * 4. Perform semantic analyses of this node.
     * 5. Pop the symbol table pushed at the 1st step.
     */
    m_current_attribute = "";
    
    p_variable.visitChildNodes(*this);
    // Check if the variable is already declared
    SymbolEntry* existing_entry = m_symbol_manager.lookup(p_variable.getNameCString());
    if (existing_entry != nullptr) {
        // 1. Cannot declare a variable with the same name in the same scope
        if (existing_entry->getLevel() == m_symbol_manager.getCurrentLevel()) {
            m_error_messages.push_back(std::make_unique<ErrorMessage>(p_variable.getLocation(), "symbol '" + std::string(p_variable.getNameCString()) + "' is redeclared"));
            return;
        }
        // 2. The symbol of a loop variable CANNOT be redeclared
        if (existing_entry->getKind() == SymbolKind::LOOP_VAR) {
            m_error_messages.push_back(std::make_unique<ErrorMessage>(p_variable.getLocation(), "symbol '" + std::string(p_variable.getNameCString()) + "' is redeclared"));
            return;
        }
    }

    // In an array declaration, each dimension's size has to be greater than 0.
    bool is_invalid_declaration = false;
    if (p_variable.getType()->getDimensions().size() > 0) {
        for (const auto& dimension : p_variable.getType()->getDimensions()) {
            if (dimension <= 0) {
                m_error_messages.push_back(std::make_unique<ErrorMessage>(p_variable.getLocation(), "'" + std::string(p_variable.getNameCString()) + "' declared as an array with an index that is not greater than 0"));
                is_invalid_declaration = true;
                break;
            }
        }
    }

    SymbolKind kind = m_current_kind;

    if (kind == SymbolKind::PROGRAM) {
        kind = SymbolKind::VARIABLE;
    }

    if (kind == SymbolKind::FUNCTION) {
        kind = SymbolKind::PARAMETER;
    }

    std::string attribute = "";
    if (!m_current_attribute.empty()) { // It means the variable is a constants
        kind = SymbolKind::CONSTANT;
        attribute = m_current_attribute;
    }

    // Add entry to symbol table
    m_symbol_manager.addEntry(
        p_variable.getLocation(),
        p_variable.getNameCString(),
        kind, 
        p_variable.getType(),
        attribute
    );
    
    // Set invalid declaration flag if needed
    if (is_invalid_declaration) {
        SymbolEntry* entry = m_symbol_manager.lookup(p_variable.getNameCString());
        if (entry != nullptr) {
            entry->setInvalidDeclaration(true);
        }
    }
}

void SemanticAnalyzer::visit(ConstantValueNode &p_constant_value) {
    /*
     * TODO:
     *
     * 1. Push a new symbol table if this node forms a scope.
     * 2. Insert the symbol into current symbol table if this node is related to
     *    declaration (ProgramNode, VariableNode, FunctionNode).
     * 3. Traverse child nodes of this node.
     * 4. Perform semantic analyses of this node.
     * 5. Pop the symbol table pushed at the 1st step.
     */
    m_current_attribute = p_constant_value.getConstantValueCString();
    p_constant_value.setType(p_constant_value.getTypeSharedPtr());
}

void SemanticAnalyzer::visit(FunctionNode &p_function) {
    /*
     * TODO:
     *
     * 1. Push a new symbol table if this node forms a scope.
     * 2. Insert the symbol into current symbol table if this node is related to
     *    declaration (ProgramNode, VariableNode, FunctionNode).
     * 3. Traverse child nodes of this node.
     * 4. Perform semantic analyses of this node.
     * 5. Pop the symbol table pushed at the 1st step.
     */
    // Check if the function is already declared
    bool is_redeclared = false;
    SymbolEntry* existing_entry = m_symbol_manager.lookup(p_function.getNameCString());
    if (existing_entry != nullptr) {
        // 1. Cannot declare a function with the same name in the same scope
        if (existing_entry->getLevel() == m_symbol_manager.getCurrentLevel()) {
            m_error_messages.push_back(std::make_unique<ErrorMessage>(p_function.getLocation(), "symbol '" + std::string(p_function.getNameCString()) + "' is redeclared"));
            is_redeclared = true;
        }
        // 2. The symbol of a loop CANNOT be redeclared
        if (existing_entry->getKind() == SymbolKind::LOOP_VAR) {
            m_error_messages.push_back(std::make_unique<ErrorMessage>(p_function.getLocation(), "symbol '" + std::string(p_function.getNameCString()) + "' is redeclared"));
            is_redeclared = true;
        }
    }
    // Remaining semantic is still needed to be performed
    if (!is_redeclared) {
        m_symbol_manager.addEntry(
            p_function.getLocation(),
            p_function.getNameCString(),
            SymbolKind::FUNCTION,
            p_function.getReturnType(),
            p_function.getFunctionAttributeString()
        );
        SymbolEntry* entry = m_symbol_manager.lookup(p_function.getNameCString());
        entry->setParameters(p_function.getParameters());
    }
    int level = m_symbol_manager.getCurrentLevel();
    SymbolTable* new_scope = new SymbolTable(level + 1);
    m_symbol_manager.pushScope(new_scope);
    m_current_kind = SymbolKind::FUNCTION;
    m_just_entered_function_scope = true;
    m_return_type_stack.push(p_function.getReturnType());
    p_function.visitChildNodes(*this);
    
    if (dump_symbol_table) {
        m_symbol_manager.dumpTopSymbolTable();
    }
    m_symbol_manager.popScope();
    m_just_entered_function_scope = false;
    m_return_type_stack.pop();
}

void SemanticAnalyzer::visit(CompoundStatementNode &p_compound_statement) {
    /*
     * TODO:
     *
     * 1. Push a new symbol table if this node forms a scope.
     * 2. Insert the symbol into current symbol table if this node is related to
     *    declaration (ProgramNode, VariableNode, FunctionNode).
     * 3. Traverse child nodes of this node.
     * 4. Perform semantic analyses of this node.
     * 5. Pop the symbol table pushed at the 1st step.
     */
    bool need_to_pop_scope = !m_just_entered_function_scope;
    if (!m_just_entered_function_scope) {
        int level = m_symbol_manager.getCurrentLevel();
        SymbolTable* new_scope = new SymbolTable(level + 1);
        m_symbol_manager.pushScope(new_scope);
    } else {
        m_just_entered_function_scope = false; 
    }
    m_current_kind = SymbolKind::VARIABLE;
    p_compound_statement.visitChildNodes(*this);
    if (need_to_pop_scope && dump_symbol_table) { // it's a new scope instead of a function scope
        m_symbol_manager.dumpTopSymbolTable();
    }
    if (need_to_pop_scope) {
        m_symbol_manager.popScope();
    } 
}

void SemanticAnalyzer::visit(PrintNode &p_print) {
    /*
     * TODO:
     *
     * 1. Push a new symbol table if this node forms a scope.
     * 2. Insert the symbol into current symbol table if this node is related to
     *    declaration (ProgramNode, VariableNode, FunctionNode).
     * 3. Traverse child nodes of this node.
     * 4. Perform semantic analyses of this node.
     * 5. Pop the symbol table pushed at the 1st step.
     */
    p_print.visitChildNodes(*this);
    ExpressionNode* target = p_print.getTarget();
    if (target == nullptr) {
        return;
    }
    PTypeSharedPtr target_type = target->getType();
    if (target_type == nullptr) {
        return;
    }
    if (!target_type->isScalar()) { 
        m_error_messages.push_back(std::make_unique<ErrorMessage>(target->getLocation(), "expression of print statement must be scalar type"));
        return;
    }
}

void SemanticAnalyzer::visit(BinaryOperatorNode &p_bin_op) {
    /*
     * TODO:
     *
     * 1. Push a new symbol table if this node forms a scope.
     * 2. Insert the symbol into current symbol table if this node is related to
     *    declaration (ProgramNode, VariableNode, FunctionNode).
     * 3. Traverse child nodes of this node.
     * 4. Perform semantic analyses of this node.
     * 5. Pop the symbol table pushed at the 1st step.
     */
    p_bin_op.visitChildNodes(*this);
    PTypeSharedPtr left_operand_type = p_bin_op.getLeftOperandType();
    PTypeSharedPtr right_operand_type = p_bin_op.getRightOperandType();
    if (left_operand_type == nullptr || right_operand_type == nullptr) {
        return;
    }
    Operator op = p_bin_op.getOperator();

    PTypeSharedPtr result_type = nullptr;
    bool is_error = false;
    if (!left_operand_type->isScalar() || !right_operand_type->isScalar()) {
        m_error_messages.push_back(std::make_unique<ErrorMessage>(p_bin_op.getLocation(), "invalid operands to binary operator '" + std::string(p_bin_op.getOpCString()) + "' ('" + std::string(left_operand_type->getPTypeCString()) + "' and '" + std::string(right_operand_type->getPTypeCString()) + "')"));
        return;
    }

    switch (op) {
        case Operator::kPlusOp:
            if (left_operand_type->isString() && right_operand_type->isString()) {
                result_type = std::make_shared<PType>(PType::PrimitiveTypeEnum::kStringType);
                break;
            }
            [[fallthrough]];
        case Operator::kMinusOp:
        case Operator::kMultiplyOp:
        case Operator::kDivideOp:
            if ((left_operand_type->isInteger() || left_operand_type->isReal()) && 
                (right_operand_type->isInteger() || right_operand_type->isReal())) {
                    if (left_operand_type->isInteger() && right_operand_type->isInteger()) {
                        result_type = std::make_shared<PType>(PType::PrimitiveTypeEnum::kIntegerType);
                    } else {
                        result_type = std::make_shared<PType>(PType::PrimitiveTypeEnum::kRealType);
                    }
                break;
            } else {
                is_error = true;
                break;
            }
        case Operator::kModOp:
            if (left_operand_type->isInteger() && right_operand_type->isInteger()) {
                result_type = std::make_shared<PType>(PType::PrimitiveTypeEnum::kIntegerType);
                break;
            } else {
                is_error = true;
                break;
            }
        case Operator::kAndOp:
        case Operator::kOrOp:
            if (left_operand_type->isBoolean() && right_operand_type->isBoolean()) {
                result_type = std::make_shared<PType>(PType::PrimitiveTypeEnum::kBoolType);
                break;
            } else {
                is_error = true;
                break;
            }
        case Operator::kLessOp:
        case Operator::kLessOrEqualOp:
        case Operator::kGreaterOp:
        case Operator::kGreaterOrEqualOp:
        case Operator::kEqualOp:
        case Operator::kNotEqualOp:
            if ((left_operand_type->isInteger() || left_operand_type->isReal()) && 
                (right_operand_type->isInteger() || right_operand_type->isReal())) {
                result_type = std::make_shared<PType>(PType::PrimitiveTypeEnum::kBoolType);
                break;
            } else {
                is_error = true;
                break;
            }
        default:
            is_error = true;
            break;
    }

    if (is_error) {
        m_error_messages.push_back(std::make_unique<ErrorMessage>(p_bin_op.getLocation(), "invalid operands to binary operator '" + std::string(p_bin_op.getOpCString()) + "' ('" + std::string(left_operand_type->getPTypeCString()) + "' and '" + std::string(right_operand_type->getPTypeCString()) + "')"));
        return;
    }

    p_bin_op.setType(result_type);
}

void SemanticAnalyzer::visit(UnaryOperatorNode &p_un_op) {
    /*
     * TODO:
     *
     * 1. Push a new symbol table if this node forms a scope.
     * 2. Insert the symbol into current symbol table if this node is related to
     *    declaration (ProgramNode, VariableNode, FunctionNode).
     * 3. Traverse child nodes of this node.
     * 4. Perform semantic analyses of this node.
     * 5. Pop the symbol table pushed at the 1st step.
     */
    p_un_op.visitChildNodes(*this);
    PTypeSharedPtr operand_type = p_un_op.getOperandType();
    Operator op = p_un_op.getOperator();
    if (operand_type == nullptr) {
        return;
    }
    if (!operand_type->isScalar()) { 
        m_error_messages.push_back(std::make_unique<ErrorMessage>(p_un_op.getLocation(), "invalid operand to unary operator '" + std::string(p_un_op.getOpCString()) + "' ('" + std::string(operand_type->getPTypeCString()) + "')"));
        return;
    }
    PTypeSharedPtr result_type = nullptr;
    if (op == Operator::kNotOp) {
        if (operand_type->isBoolean()) {
            result_type = std::make_shared<PType>(PType::PrimitiveTypeEnum::kBoolType);
        } else {
            m_error_messages.push_back(std::make_unique<ErrorMessage>(p_un_op.getLocation(), "invalid operand to unary operator '" + std::string(p_un_op.getOpCString()) + "' ('" + std::string(operand_type->getPTypeCString()) + "')"));
            return;
        }
    } else if (op == Operator::kNegOp) {
        if (operand_type->isInteger() || operand_type->isReal()) {
            result_type = std::make_shared<PType>(*operand_type);
        } else {
            m_error_messages.push_back(std::make_unique<ErrorMessage>(p_un_op.getLocation(), "invalid operand to unary operator '" + std::string(p_un_op.getOpCString()) + "' ('" + std::string(operand_type->getPTypeCString()) + "')"));
            return;
        }
    }
    p_un_op.setType(result_type);
}

void SemanticAnalyzer::visit(FunctionInvocationNode &p_func_invocation) {
    /*
     * TODO:
     *
     * 1. Push a new symbol table if this node forms a scope.
     * 2. Insert the symbol into current symbol table if this node is related to
     *    declaration (ProgramNode, VariableNode, FunctionNode).
     * 3. Traverse child nodes of this node.
     * 4. Perform semantic analyses of this node.
     * 5. Pop the symbol table pushed at the 1st step.
     */
    p_func_invocation.visitChildNodes(*this);
    SymbolEntry* existing_entry = m_symbol_manager.lookup(p_func_invocation.getNameCString());

    //The identifier has to be in symbol tables.
    if (existing_entry == nullptr) {
        m_error_messages.push_back(std::make_unique<ErrorMessage>(p_func_invocation.getLocation(), "use of undeclared symbol '" + std::string(p_func_invocation.getNameCString()) + "'"));
        return;
    }

    // The kind of symbol has to be function.
    if (existing_entry->getKind() != SymbolKind::FUNCTION) {
        m_error_messages.push_back(std::make_unique<ErrorMessage>(p_func_invocation.getLocation(), "call of non-function symbol '" + std::string(p_func_invocation.getNameCString()) + "'"));
        return;
    }

    // The number of arguments must be the same as one of the parameters.
    if (existing_entry->getParameters().size() != p_func_invocation.getArgs().size()) {
        m_error_messages.push_back(std::make_unique<ErrorMessage>(p_func_invocation.getLocation(), "too few/much arguments provided for function '" + std::string(p_func_invocation.getNameCString()) + "'"));
        return;
    }

    // Traverse arguments:
    for (size_t i = 0; i < p_func_invocation.getArgs().size(); i++) {
        ExpressionNode* arg = p_func_invocation.getArgs()[i].get();
        PTypeSharedPtr arg_type = arg->getType();
        if (arg_type == nullptr) {
            return;
        }
        
        // Get parameter type from DeclNode's first variable
        const auto& param_decl = existing_entry->getParameters()[i];
        if (param_decl->getVariables().empty()) {
            return;
        }
        PTypeSharedPtr param_type = param_decl->getVariables()[0]->getType();
        
        if (!arg_type->isCompatible(param_type)) {
            m_error_messages.push_back(std::make_unique<ErrorMessage>(arg->getLocation(), "incompatible type passing '" + std::string(arg_type->getPTypeCString()) + "' to parameter of type '" + std::string(param_type->getPTypeCString()) + "'"));
            return;
        }
    }

    PTypeSharedPtr result_type = std::make_shared<PType>(*existing_entry->getType());
    p_func_invocation.setType(result_type);
}

void SemanticAnalyzer::visit(VariableReferenceNode &p_variable_ref) {
    /*
     * TODO:
     *
     * 1. Push a new symbol table if this node forms a scope.
     * 2. Insert the symbol into current symbol table if this node is related to
     *    declaration (ProgramNode, VariableNode, FunctionNode).
     * 3. Traverse child nodes of this node.
     * 4. Perform semantic analyses of this node.
     * 5. Pop the symbol table pushed at the 1st step.
     */
    p_variable_ref.visitChildNodes(*this);
    SymbolEntry* existing_entry = m_symbol_manager.lookup(p_variable_ref.getNameCString());

    if (existing_entry == nullptr) {
        m_error_messages.push_back(std::make_unique<ErrorMessage>(p_variable_ref.getLocation(), "use of undeclared symbol '" + std::string(p_variable_ref.getNameCString()) + "'"));
        return;
    }


    if (existing_entry->getKind() != SymbolKind::PARAMETER && 
        existing_entry->getKind() != SymbolKind::VARIABLE && 
        existing_entry->getKind() != SymbolKind::LOOP_VAR && 
        existing_entry->getKind() != SymbolKind::CONSTANT) {
        m_error_messages.push_back(std::make_unique<ErrorMessage>(p_variable_ref.getLocation(), "use of non-variable symbol '" + std::string(p_variable_ref.getNameCString()) + "'"));
        return;
    }

    if (existing_entry->isInvalidDeclaration()) {   
        return;
    }

    for (const auto& index : p_variable_ref.getIndices()) {
        if (index->getType() == nullptr) {
            return;
        }
        if (index->getType()->getPrimitiveType() != PType::PrimitiveTypeEnum::kIntegerType) {
            m_error_messages.push_back(std::make_unique<ErrorMessage>(index->getLocation(), "index of array reference must be an integer"));
            return;
        }
    }

    if (p_variable_ref.getIndices().size() > existing_entry->getType()->getDimensions().size()) {
        m_error_messages.push_back(std::make_unique<ErrorMessage>(p_variable_ref.getLocation(), "there is an over array subscript on '" + std::string(p_variable_ref.getNameCString()) + "'"));
        return;
    }
    PTypeSharedPtr result_type = std::make_shared<PType>(*existing_entry->getType());
    for (size_t i = 0; i < p_variable_ref.getIndices().size(); i++) {
        result_type->popDimension();
    }

    p_variable_ref.setType(result_type);
}

void SemanticAnalyzer::visit(AssignmentNode &p_assignment) {
    /*
     * TODO:
     *
     * 1. Push a new symbol table if this node forms a scope.
     * 2. Insert the symbol into current symbol table if this node is related to
     *    declaration (ProgramNode, VariableNode, FunctionNode).
     * 3. Traverse child nodes of this node.
     * 4. Perform semantic analyses of this node.
     * 5. Pop the symbol table pushed at the 1st step.
     */
    p_assignment.visitChildNodes(*this);
    VariableReferenceNode* target = p_assignment.getTarget();
    if (target == nullptr) {
        return;
    }
    PTypeSharedPtr target_type = target->getType();
    if (target_type == nullptr) { 
        return;
    }

    // The type of the result of the variable reference cannot be an array type.
    if (!target_type->isScalar()) {
        m_error_messages.push_back(std::make_unique<ErrorMessage>(target->getLocation(), "array assignment is not allowed"));
        return;
    }

    // The variable reference cannot be a reference to a constant variable.
    SymbolEntry* symbol_entry = m_symbol_manager.lookup(target->getNameCString());
    if (symbol_entry != nullptr && symbol_entry->getKind() == SymbolKind::CONSTANT) {
        m_error_messages.push_back(std::make_unique<ErrorMessage>(target->getLocation(), "cannot assign to variable '" + std::string(target->getNameCString()) + "' which is a constant"));
        return;
    }

    // The variable reference cannot be a reference to a loop variable, unless the current context is for loop_var initialization.
    if (symbol_entry != nullptr && symbol_entry->getKind() == SymbolKind::LOOP_VAR && m_current_kind != SymbolKind::LOOP_VAR) {
        m_error_messages.push_back(std::make_unique<ErrorMessage>(target->getLocation(), "the value of loop variable cannot be modified inside the loop body"));
        return;
    }

    // The type of the result of the expression cannot be an array type.
    ExpressionNode* expression = p_assignment.getExpression();
    if (expression == nullptr) {
        return;
    }
    PTypeSharedPtr expression_type = expression->getType();
    if (expression_type == nullptr) {
        return;
    }
    if (!expression_type->isScalar()) {
        m_error_messages.push_back(std::make_unique<ErrorMessage>(expression->getLocation(), "array assignment is not allowed"));
        return;
    }

    // The type of the variable reference (lvalue) must be the same as the one of the expression after appropriate type coercion.
    if (!expression_type->isCompatible(target_type)) {
        m_error_messages.push_back(std::make_unique<ErrorMessage>(p_assignment.getLocation(), "assigning to '" + std::string(target_type->getPTypeCString()) + "' from incompatible type '" + std::string(expression->getType()->getPTypeCString()) + "'"));
        return;
    }
}

void SemanticAnalyzer::visit(ReadNode &p_read) {
    /*
     * TODO:
     *
     * 1. Push a new symbol table if this node forms a scope.
     * 2. Insert the symbol into current symbol table if this node is related to
     *    declaration (ProgramNode, VariableNode, FunctionNode).
     * 3. Traverse child nodes of this node.
     * 4. Perform semantic analyses of this node.
     * 5. Pop the symbol table pushed at the 1st step.
     */
    p_read.visitChildNodes(*this);

    VariableReferenceNode* target = p_read.getTarget();
    if (target == nullptr) {
        return;
    }

    PTypeSharedPtr target_type = target->getType();
    if (target_type == nullptr) {
        return;
    }

    // The type of the variable reference must be scalar type.
    if (!target_type->isScalar()) {
        m_error_messages.push_back(std::make_unique<ErrorMessage>(target->getLocation(), "variable reference of read statement must be scalar type"));
        return;
    }

    // The kind of symbol of the variable reference cannot be constant or loop_var.
    SymbolEntry* symbol_entry = m_symbol_manager.lookup(target->getNameCString());
    if (symbol_entry != nullptr && 
        (symbol_entry->getKind() == SymbolKind::CONSTANT || 
         symbol_entry->getKind() == SymbolKind::LOOP_VAR)) {
        m_error_messages.push_back(std::make_unique<ErrorMessage>(target->getLocation(), "variable reference of read statement cannot be a constant or loop variable"));
        return;
    }
}

void SemanticAnalyzer::visit(IfNode &p_if) {
    /*
     * TODO:
     *
     * 1. Push a new symbol table if this node forms a scope.
     * 2. Insert the symbol into current symbol table if this node is related to
     *    declaration (ProgramNode, VariableNode, FunctionNode).
     * 3. Traverse child nodes of this node.
     * 4. Perform semantic analyses of this node.
     * 5. Pop the symbol table pushed at the 1st step.
     */
    p_if.visitChildNodes(*this);
    ExpressionNode* condition = p_if.getCondition();
    if (condition == nullptr) {
        return;
    }
    PTypeSharedPtr condition_type = condition->getType();
    if (condition_type == nullptr) {
        return;
    }       
    if (!condition_type->isBoolean()) {
        m_error_messages.push_back(std::make_unique<ErrorMessage>(condition->getLocation(), "the expression of condition must be boolean type"));
        return;
    }
}

void SemanticAnalyzer::visit(WhileNode &p_while) {
    /*
     * TODO:
     *
     * 1. Push a new symbol table if this node forms a scope.
     * 2. Insert the symbol into current symbol table if this node is related to
     *    declaration (ProgramNode, VariableNode, FunctionNode).
     * 3. Traverse child nodes of this node.
     * 4. Perform semantic analyses of this node.
     * 5. Pop the symbol table pushed at the 1st step.
     */
    p_while.visitChildNodes(*this);
    ExpressionNode* condition = p_while.getCondition();
    if (condition == nullptr) {
        return;
    }
    PTypeSharedPtr condition_type = condition->getType();
    if (condition_type == nullptr) {
        return;
    }
    if (!condition_type->isBoolean()) {
        m_error_messages.push_back(std::make_unique<ErrorMessage>(condition->getLocation(), "the expression of condition must be boolean type"));
        return;
    }
}

void SemanticAnalyzer::visit(ForNode &p_for) {
    /*
     * TODO:
     *
     * 1. Push a new symbol table if this node forms a scope.
     * 2. Insert the symbol into current symbol table if this node is related to
     *    declaration (ProgramNode, VariableNode, FunctionNode).
     * 3. Traverse child nodes of this node.
     * 4. Perform semantic analyses of this node.
     * 5. Pop the symbol table pushed at the 1st step.
     */
    DeclNode* loop_var_decl = p_for.getLoopVarDecl();
    AssignmentNode* init_stmt = p_for.getInitStmt();
    ExpressionNode* end_condition = p_for.getEndCondition();
    CompoundStatementNode* body = p_for.getBody();
    int level = m_symbol_manager.getCurrentLevel();
    SymbolTable* new_scope = new SymbolTable(level + 1);
    m_symbol_manager.pushScope(new_scope);
    SymbolKind prev_kind = m_current_kind;
    m_current_kind = SymbolKind::LOOP_VAR;

    p_for.visitChildNodes(*this);

    if (dump_symbol_table) { 
        m_symbol_manager.dumpTopSymbolTable();
    }
    m_symbol_manager.popScope();
    m_current_kind = prev_kind;

    if (!init_stmt || !end_condition) {
        return;
    }

    auto *lower_bound_node = init_stmt->getExpression();
    auto *upper_bound_node = end_condition;

    auto *lower_const = dynamic_cast<ConstantValueNode*>(lower_bound_node);
    auto *upper_const = dynamic_cast<ConstantValueNode*>(upper_bound_node);
    if (lower_const && upper_const) {
        PTypeSharedPtr lower_type = lower_const->getTypeSharedPtr();
        PTypeSharedPtr upper_type = upper_const->getTypeSharedPtr();
        
        // Both must be integer or real type
        if ((lower_type->isInteger() || lower_type->isReal()) && 
            (upper_type->isInteger() || upper_type->isReal())) {
            
            double lower_value, upper_value;
            
            // Extract numeric values
            if (lower_type->isInteger()) {
                lower_value = static_cast<double>(lower_const->getConstantValue()->getIntegerValue());
            } else {
                lower_value = lower_const->getConstantValue()->getRealValue();
            }
            
            if (upper_type->isInteger()) {
                upper_value = static_cast<double>(upper_const->getConstantValue()->getIntegerValue());
            } else {
                upper_value = upper_const->getConstantValue()->getRealValue();
            }
            
            // Check if lower_bound >= upper_bound (not strictly incremental)
            if (lower_value >= upper_value) {
                m_error_messages.push_back(std::make_unique<ErrorMessage>(
                    p_for.getLocation(), 
                    "the lower bound and upper bound of iteration count must be in the incremental order"
                ));
            }
        }
    }
    
}

void SemanticAnalyzer::visit(ReturnNode &p_return) {
    /*
     * TODO:
     *
     * 1. Push a new symbol table if this node forms a scope.
     * 2. Insert the symbol into current symbol table if this node is related to
     *    declaration (ProgramNode, VariableNode, FunctionNode).
     * 3. Traverse child nodes of this node.
     * 4. Perform semantic analyses of this node.
     * 5. Pop the symbol table pushed at the 1st step.
     */
    p_return.visitChildNodes(*this);
    // The current context shouldn't be in the program or a procedure since their return type is void.
    if (m_return_type_stack.top()->getPrimitiveType() == PType::PrimitiveTypeEnum::kVoidType) {
        m_error_messages.push_back(std::make_unique<ErrorMessage>(p_return.getLocation(), "program/procedure should not return a value"));
        return;
    }

    // The type of the result of the expression (return value) must be the same type as the return type of current function after appropriate type coercion.
    ExpressionNode* return_value = p_return.getReturnValue();
    if (return_value == nullptr) {
        return;
    }
    PTypeSharedPtr return_value_type = return_value->getType();
    if (return_value_type == nullptr) {
        return;
    }
    if (!return_value_type->isCompatible(m_return_type_stack.top())) {
        m_error_messages.push_back(std::make_unique<ErrorMessage>(return_value->getLocation(), "return '" + std::string(return_value_type->getPTypeCString()) + "' from a function with return type '" + std::string(m_return_type_stack.top()->getPTypeCString()) + "'"));
        return;
    }
}   
