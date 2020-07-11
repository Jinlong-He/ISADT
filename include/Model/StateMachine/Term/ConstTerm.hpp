//
//  Term.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//
//TODO
#ifndef Model_ConstTerm_hpp
#define Model_ConstTerm_hpp
#include "Term.hpp"
#include "../../Process/Attribute.hpp"

namespace isadt {
  /// \breif the attribute term in the action
    class ConstTerm : public Term {
    public:
        ConstTerm()
            : typeStr_(""),
              valueStr_("") {}

        ConstTerm(const string& tyepStr, const string& valueStr)
            : typeStr_(tyepStr),
              valueStr_(valueStr) {}

        const string& getTypeStr() const;
        bool getBoolValue() const;
        int getIntValue() const;
        virtual string to_string() const {
            return valueStr_;
        }

        UserType* getType() const {
            return nullptr;
        }
    private:
        string typeStr_;
        string valueStr_;
    };
}

#endif /* Model_AttributeTerm_hpp */
