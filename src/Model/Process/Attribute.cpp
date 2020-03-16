#include "Model/Process/Attribute.hpp"
namespace isadt {
    Type* Attribute::getType() const {
        return type;
    }

    void Attribute::setType(Type* _type) {
        type = _type;
    }

    const string& Attribute::getIdentifier() const {
        return identifier;
    }

    void Attribute::setIdentifier(const string& _identifier) {
        identifier = _identifier;
    }

    const string Attribute::toString() const {
        return type -> getName() + " " + identifier;
    }
}
