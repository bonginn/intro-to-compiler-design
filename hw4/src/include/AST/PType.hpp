#ifndef AST_P_TYPE_H
#define AST_P_TYPE_H

#include <memory>
#include <string>
#include <vector>

class PType;

using PTypeSharedPtr = std::shared_ptr<PType>;

class PType {
  public:
    enum class PrimitiveTypeEnum : uint8_t {
        kVoidType,
        kIntegerType,
        kRealType,
        kBoolType,
        kStringType
    };
    std::vector<uint64_t> getDimensions() const { return m_dimensions; }

  private:
    PrimitiveTypeEnum m_type;
    std::vector<uint64_t> m_dimensions;
    mutable std::string m_type_string;
    mutable bool m_type_string_is_valid = false;

  public:
    ~PType() = default;
    PType(const PrimitiveTypeEnum type) : m_type(type) {}

    void setDimensions(std::vector<uint64_t> &p_dims) {
        m_dimensions = std::move(p_dims);
    }

    PrimitiveTypeEnum getPrimitiveType() const { return m_type; }
    bool isString() const { return m_type == PrimitiveTypeEnum::kStringType; }
    bool isInteger() const { return m_type == PrimitiveTypeEnum::kIntegerType; }
    bool isReal() const { return m_type == PrimitiveTypeEnum::kRealType; }
    bool isBoolean() const { return m_type == PrimitiveTypeEnum::kBoolType; }
    const char *getPTypeCString() const;
    bool isScalar() const { 
      if (m_dimensions.size() == 0 && m_type != PrimitiveTypeEnum::kVoidType) {
        return true;
      }
      return false;
    }
    void popDimension() {
        m_dimensions.erase(m_dimensions.begin());
    }
    bool isCompatible(const PTypeSharedPtr &p_other) const;
};

#endif
