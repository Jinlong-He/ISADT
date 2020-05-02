//
//  Guard.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_Guard_hpp
#define Model_Guard_hpp
#include <string>
#include "../Expression.hpp"
using std::string;

namespace isadt {
	/// \brief Guard condition on the transition.
	class Guard {
      public:
        Guard();
        Guard(const string& toParse);
        Guard(Expression* expression);

        Expression* getGuardExpression();
        void setGuardExpression(Expression* expression);
        string to_stirng() const;
    private:
        Expression* expression_;
	};
}

#endif /* Model_Guard_hpp */
