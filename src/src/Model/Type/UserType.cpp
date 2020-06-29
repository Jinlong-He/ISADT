#include "Model/Type/UserType.hpp"
namespace isadt {
    const list<Attribute*>& UserType::getParameters() const {
        return parameters_;
    }

    void UserType::setParameters(const list<Attribute*>& parameters) {
        parameters_ = parameters;
    }

    void UserType::addAttribute(Attribute* attr) {
        parameters_.push_back(attr);
    }

    void UserType::addMethod(Method* m) {
        methods_.push_back(m);
    }

    void UserType::setBase(UserType* base) {
        base_ = base;
    }
}
