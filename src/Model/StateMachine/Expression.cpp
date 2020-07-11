#include "Model/StateMachine/Expression.hpp"
namespace isadt{
    string Expression::to_string() const {
        if (isSingle_) {
            if (op_ == "!" || op_ == ".")
                return op_ + term1_ -> to_string();
            if (op_ == "()")
                return "(" + term1_ -> to_string() + ")";
            if (op_ == "[]")
                return "[" + term1_ -> to_string() + "]";
        } else {
            return term1_ -> to_string() + op_ + term2_ -> to_string();
        }
        return "";
    }
}
