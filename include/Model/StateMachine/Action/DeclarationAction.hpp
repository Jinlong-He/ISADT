// attribute
#ifndef Model_DeclarationAction_hpp
#define Model_DeclarationAction_hpp
#include "Action.hpp"
namespace isadt {
  /// \brief the DeclarationAction.
  class DeclarationAction : public Action {
  public:
    DeclarationAction()
        : attribute_(nullptr) {}

    DeclarationAction(Attribute* attr, const string& value = "")
        : attribute_(attr),
          value_(value) {}
    
    DeclarationAction(const string& xml);
    string to_string() const {
        string res = attribute_ -> getType() -> getName() + " " + attribute_ -> getIdentifier();
        for (int i = 0; i < attribute_ -> getArray(); i++) {
            res += "[]";
        }
        return res;
    }
  private:
    Attribute* attribute_;
    string value_;
  };
}

#endif /* Model_AssignmentTerm_hpp */
