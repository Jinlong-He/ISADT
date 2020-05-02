#include "Model/Type/UserType.hpp"
namespace isadt {
    const list<Attribute*>& UserType::getParameters() const {
        return parameters_;
    }

    void UserType::setParameters(const list<Attribute*>& parameters) {
        parameters_ = parameters;
    }

    void UserType::addParameter(Attribute* attr) {
        parameters_.push_back(attr);
    }
}
