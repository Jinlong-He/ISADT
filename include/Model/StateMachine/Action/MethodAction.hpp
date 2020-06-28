// method term
#ifndef Model_MethodAction_hpp
#define Model_MethodAction_hpp
#include "Action.hpp"
#include "../Term/MethodTerm.hpp"
namespace isadt {
  /// \brief the AssignmentTerm contains AttributeTerm and MethodTerm.
  class MethodAction : public Action {
  public:
    MethodAction();
    MethodAction(const string& xml);

    string to_stirng() const;
  private:
        MethodTerm* methodTerm_;
        string xml_;
  };
}

#endif /* Model_AssignmentTerm_hpp */
