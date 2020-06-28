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
  class Expression {
  public:
    Expression();
    Expression(string value);

    Expression(Expression* expressionA);
    Expression(Expression* expressionA, Expression* expressionB, string binaryOp);
    Expression* getExpressionA();
    Expression* getExpressionB();
    string getBinaryOp();
    bool isSingledExpression();
  private:
    Expression* expressionA_;
    Expression* expressionB_;
    bool isSingleExpression_;
    string binaryOp_;
    string xml_;

  };

  class atomicExpression : public Expression {
    private:
      Term* termA_;
      Term* termB_;
      bool isSingleTerm_;
      string binaryOp_;
      string xml_;
  };
}

#endif /* Model_Expression_hpp */
