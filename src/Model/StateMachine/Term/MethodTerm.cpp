#include "Model/StateMachine/Term/MethodTerm.hpp"
namespace isadt {
    void MethodTerm::pushfrontArg(Term* term) {
        args_.push_front(term);
    }

    string MethodTerm::to_string() const {
        string res = method_ -> getName() + "(";
        for (auto arg : args_) {
            res += arg -> to_string() + ",";
        }
        res[res.length() - 1] = ')';
        return res + Term::to_string();
    }

    UserType* MethodTerm::getType() const {
        return method_  -> getReturnType();
    }
}
