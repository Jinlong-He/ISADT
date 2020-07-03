//
//  ArithmeticTerm.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_ArithmeticTerm_hpp
#define Model_ArithmeticTerm_hpp
#include "Term.hpp"
#include "../../Process/Attribute.hpp"

namespace isadt {
  /// \breif the attribute term in the action
  class ArithmeticTerm : public Term {
  public:
    ArithmeticTerm()
        : Term(),
          attribute_(nullptr) {}

    ArithmeticTerm(Arithmetic* attribute)
        : attribute_(attribute) {}

    ArithmeticTerm(const string& toParse);

    bool isAMethodCall();
    bool isAVariableSetting();
    bool containAMethodCall();
    string to_stirng() const;
  private:
    Term* lhs_;
  };
}

#endif /* Model_ArithmeticTerm_hpp */
