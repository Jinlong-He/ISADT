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

        ~Action() {
            for (auto term : terms_) {
                delete term;
                term = nullptr;
            }
        }

        MethodTerm* mkMethodTerm(MethodBase* method);
        AttributeTerm* mkAttributeTerm(Attribute* attr);
        ConstTerm* mkConstTerm(Attribute* attr);

        Action(const string& toParse);
        virtual string to_string() const;
    private:
        list<Term*> terms_;
	};
}
#endif /* Model_Action_hpp */
