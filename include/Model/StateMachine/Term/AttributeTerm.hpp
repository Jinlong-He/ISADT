//
//  Term.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_AttributeTerm_hpp
#define Model_AttributeTerm_hpp
#include "Term.hpp"
#include "../../Process/Attribute.hpp"

namespace isadt {
  /// \breif the attribute term in the action
  class AttributeTerm : public Term {
  public:
    AttributeTerm();
    AttributeTerm(Attribute* attribute);
    AttributeTerm(const string& toParse);

    bool isAMethodCall();
    bool isAVariableSetting();
    bool containAMethodCall();
    string to_stirng() const;
  private:
    Attribute* attribute_;       //< attribute of the term
  };
}

#endif /* Model_AttributeTerm_hpp */
