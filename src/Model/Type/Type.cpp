#include "Model/Type/Type.hpp"
namespace isadt {
    const string& Type::getName() const {
        return name_;
    }

    void Type::setName(const string& name) {
        name_ = name;
    }
}
