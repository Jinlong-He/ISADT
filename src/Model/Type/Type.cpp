#include "Model/Type/Type.hpp"
namespace isadt {
    const string& Type::getName() const {
        return name;
    }

    void Type::setName(const string& _name) {
        name = _name;
    }
}
