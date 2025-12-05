#ifndef AST_CONSTANT_H
#define AST_CONSTANT_H

#include "AST/PType.hpp"

#include <cstdint>
#include <cstdlib>

class Constant {
  public:
    union ConstantValue {
        int64_t integer;
        double real;
        char *string;
        bool boolean;
    };

  private:
    PTypeSharedPtr m_type;
    ConstantValue m_value;
    mutable std::string m_constant_value_string;
    mutable bool m_constant_value_string_is_valid = false;

  public:
    ~Constant() {
        if (m_type->getPrimitiveType() ==
            PType::PrimitiveTypeEnum::kStringType) {
            free(m_value.string);
        }
    }
    Constant(const PTypeSharedPtr &p_type, const ConstantValue value)
        : m_type(p_type), m_value(value) {}


    const PTypeSharedPtr &getTypeSharedPtr() const { return m_type; }
    const char *getConstantValueCString() const;
    
    // Get numeric values (only valid for integer/real types)
    int64_t getIntegerValue() const {
        return m_value.integer;
    }
    double getRealValue() const {
        return m_value.real;
    }
};

#endif
