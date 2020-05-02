#include "Model/Process/Attribute.hpp"
namespace isadt {
    Type* Attribute::getType() const {
        return type_;
    }

    void Attribute::setType(Type* type) {
        type_ = type;
    }

    const string& Attribute::getIdentifier() const {
        return identifier_;
    }

    void Attribute::setIdentifier(const string& identifier) {
        identifier_ = identifier;
    }

    const string Attribute::toString() const {
        return type_ -> getName() + " " + identifier_;
    }
}
