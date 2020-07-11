//
//  Action.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_Action_hpp
#define Model_Action_hpp
#include <list>
#include "../Term/MethodTerm.hpp"

using std::list;
namespace isadt {
	/// \breif the Action on the transition
	class Action {
	public:
		Action() {}

        virtual ~Action() {}

        Action(const string& toParse);
        virtual string to_string() const;
    private:
	};
}
#endif /* Model_Action_hpp */
