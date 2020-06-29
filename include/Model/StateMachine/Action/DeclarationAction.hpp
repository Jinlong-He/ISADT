// attribute
#ifndef Model_DeclarationAction_hpp
#define Model_DeclarationAction_hpp
#include "Action.hpp"
namespace isadt {
  /// \brief the AssignmentTerm contains AttributeTerm and MethodTerm.
  class AssignmentAction : public Action {
  public:
    AssignmentAction();
    AssignmentAction(const string& xml);

    string to_stirng() const;
  private:
		AttributeTerm* lhs_;     //< leftHand of the assignment
		Term* rhs_;              //< rightHand can be an attribute or a method call.
        string xml_;
  };
}

#endif /* Model_AssignmentTerm_hpp */
