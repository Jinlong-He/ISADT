#include "Model/StateMachine/Term/AttributeTerm.hpp"
namespace isadt {
    string AttributeTerm::to_string() const {
        return attribute_ -> getIdentifier() + Term::to_string();
    }

    UserType* AttributeTerm::getType() const {
        return attribute_ -> getType();
    }
}
