#include "AST/PType.hpp"
#include <string>

std::string PType::getTypeString() {
    std::string arrDimensions = " ";
    for (auto &dim : dimensions) {
        arrDimensions += "[" + std::to_string(dim) + "]";
    }
    if (arrDimensions == " ") { // If there is no dimensions, set it to empty string
        arrDimensions = "";
    }
    switch (type) {
        case kInteger:
            return "integer" + arrDimensions;
        case kReal:
            return "real" + arrDimensions;
        case kString:
            return "string" + arrDimensions;
        case kBoolean:
            return "boolean" + arrDimensions;
        default:
            return "unknown";
    }
}
