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

    AssignmentAction(Term* lhs, Term* rhs = nullptr)
        : lhs_(lhs),
          rhs_(rhs) {}

    string to_string() const {
        if (rhs_)
            return lhs_ -> to_string() + " = " + rhs_ -> to_string();
        return lhs_ -> to_string();
    }
  private:
		Term* lhs_;     //< leftHand of the assignment
		Term* rhs_;              //< rightHand can be an attribute or a method call.
        string xml_;
  };
}

#endif /* Model_AssignmentTerm_hpp */
