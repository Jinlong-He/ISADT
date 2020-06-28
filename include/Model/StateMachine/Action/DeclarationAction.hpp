// attribute
#ifndef Model_DeclarationAction_hpp
#define Model_DeclarationAction_hpp
#include "Action.hpp"
namespace isadt {
  /// \brief the DeclarationAction.
  class DeclarationAction : public Action {
  public:
    DeclarationAction();
    DeclarationAction(const string& xml);
    string to_stirng() const;
  private:
    Attribute* attribute_;
    string value_;
  };
}

#endif /* Model_AssignmentTerm_hpp */
