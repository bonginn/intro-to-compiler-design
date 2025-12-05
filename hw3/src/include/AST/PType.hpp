#ifndef __AST_PTYPE_H
#define __AST_PTYPE_H

#include <vector>
#include <string>

class PType {
public:
    enum PrimitiveTypeEnum {
        kInteger,
        kReal,
        kString,
        kBoolean,
        kArray,
    };

    PrimitiveTypeEnum type;
    std::vector <int> dimensions;

    PType(PrimitiveTypeEnum t) : type(t) {}

    void addDimension(int dim) {
        dimensions.push_back(dim);
    }

    std::string getTypeString();


private:
    mutable std::string cachedTypeString;
};

#endif