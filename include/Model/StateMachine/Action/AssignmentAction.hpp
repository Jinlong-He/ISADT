//
//  Term.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_AssignmentTerm_hpp
#define Model_AssignmentTerm_hpp
#include "Action.hpp"
namespace isadt {
  /// \brief the AssignmentTerm contains AttributeTerm and MethodTerm.
  class AssignmentAction : public Action {
  private:
		AttributeTerm* lhs;     //< leftHand of the assignment
		Term* rhs;              //< rightHand can be an attribute or a method call.
        string xml_value;
  public:
    AssignmentAction();
    AssignmentAction(const string& _value);

    string to_stirng() const;
  };
}

#endif /* Model_AssignmentTerm_hpp */
