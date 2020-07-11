//
//  ListTerm.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_ListTerm_hpp
#define Model_ListTerm_hpp
#include "Term.hpp"

namespace isadt {
    /// \breif the attribute term in the action
    class ListTerm : public Term {
    public:
        ListTerm()
            : Term(){}

        void pushfrontTerm(Term* term) {
            list_.push_front(term);
        }
        virtual string to_string() const {
            string res = "{";
            for (auto term: list_) {
                res += term -> to_string() + ",";
            }
            res[res.length() - 1] = '}';
            return res;
        }

        virtual UserType* getType() const {
            return nullptr;
        }
    private:
        list<Term*> list_;
    };
}

#endif /* Model_ListTerm_hpp */
