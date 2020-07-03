//
//  Term.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_AssignmentAction_hpp
#define Model_AssignmentAction_hpp
#include "Action.hpp"
namespace isadt {
  /// \brief the AssignmentTerm contains AttributeTerm and MethodTerm.
  class AssignmentAction : public Action {
  public:
    AssignmentAction()
        : lhs_(nullptr),
          rhs_(nullptr) {}

    AssignmentAction(Attribute* attr)
        : lhs_(mkAttributeTerm(attr)),
          rhs_(nullptr) {}

    AssignmentAction(AttributeTerm* lhs, Term* rhs)
        : lhs_(lhs),
          rhs_(rhs) {}

    void setRhs(Term* term);

    string to_stirng() const;
  private:
		AttributeTerm* lhs_;     //< leftHand of the assignment
		Term* rhs_;              //< rightHand can be an attribute or a method call.
        string xml_;
  };
}

#endif /* Model_AssignmentTerm_hpp */
