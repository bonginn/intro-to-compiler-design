#include "AST/PType.hpp"

const char *kTypeString[] = {"void", "integer", "real", "boolean", "string"};

// logical constness
const char *PType::getPTypeCString() const {
    if (!m_type_string_is_valid) {
        m_type_string += kTypeString[static_cast<size_t>(m_type)];

        if (m_dimensions.size() != 0) {
            m_type_string += " ";

            for (const auto &dim : m_dimensions) {
                m_type_string += "[" + std::to_string(dim) + "]";
            }
        }
        m_type_string_is_valid = true;
    }

    return m_type_string.c_str();
}

bool PType::isCompatible(const PTypeSharedPtr &p_other) const {
    if (p_other == nullptr) {
        return false;
    }
    
    // Check dimensions match
    if (m_dimensions.size() != p_other->m_dimensions.size()) {
        return false;
    }
    
    for (size_t i = 0; i < m_dimensions.size(); i++) {
        if (m_dimensions[i] != p_other->m_dimensions[i]) {
            return false;
        }
    }
    
    // For scalar types, integer can be passed to real
    if (m_dimensions.size() == 0) {
        // If parameter (p_other) is real, integer (this) argument is compatible
        if (p_other->isReal() && m_type == PrimitiveTypeEnum::kIntegerType) {
            return true;
        }
        // If parameter (p_other) is real, real (this) argument is compatible
        if (p_other->isReal() && m_type == PrimitiveTypeEnum::kRealType) {
            return true;
        }
        // If parameter (p_other) is integer, only integer (this) argument is compatible
        if (p_other->isInteger() && m_type == PrimitiveTypeEnum::kIntegerType) {
            return true;
        }
        // For other types, must match exactly
        return m_type == p_other->m_type;
    } else {
        // For array types, base types must match exactly
        return m_type == p_other->m_type;
    }
}
