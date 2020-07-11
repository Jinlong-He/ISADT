//
//  Term.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_Term_hpp
#define Model_Term_hpp

#include <string>
#include "../../Type/UserType.hpp"
using std::string;

namespace isadt {
	/// \breif the term in the action has two inheritance class AttributeTerm and MethodTerm.
	class Term {

	public:
        Term() {}

        virtual ~Term() {}

		bool isValidName(string _name);
		bool containAMethodCall(); //< check if the term has a MethodTerm subclass.

        void addChild(Term* term) {
            children_.push_back(term);
        }

        virtual string to_string() const {
            string res = "";
            for (auto term : children_) {
                res += term -> to_string();
            }
            return res;
        }

        virtual UserType* getType() const {
            return nullptr;
        }

	private:
        list<Term*> children_;
	};
}

#endif /* Model_Term_hpp */
