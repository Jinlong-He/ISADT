//
//  Expression.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_Expression_hpp
#define Model_Expression_hpp
#include <string>
#include "Term/Term.hpp"
using std::string;

namespace isadt {
    /// \brief Expression in the Guard condition.
    class Expression : public Term{
    public:
        Expression()
            : term1_(nullptr),
              term2_(nullptr) {}

        Expression(const string& op, Term* term1, Term* term2 = nullptr)
            : op_(op),
              term1_(term1),
              term2_(term2),
              isSingle_(term2 == nullptr) {}

        virtual ~Expression() {}

        Term* getTerm1();
        Term* getTerm2();

        string getOp();
        bool isSingledExpression();
        virtual string to_string() const;
        virtual UserType* getType() const {
            return term1_ -> getType();
        }
    private:
        string op_;
        Term* term1_;
        Term* term2_;
        bool isSingle_;
        string xml_;
    };
}

#endif /* Model_Expression_hpp */
