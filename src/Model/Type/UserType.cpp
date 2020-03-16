#include "Model/Type/UserType.hpp"
namespace isadt {
    const list<Attribute*>& UserType::getParameters() const {
        return parameters;
    }

    void UserType::setParameters(const list<Attribute*>& _parameters) {
        parameters = _parameters;
    }

    void UserType::addParameter(Attribute* attr) {
        parameters.push_back(attr);
    }
}
