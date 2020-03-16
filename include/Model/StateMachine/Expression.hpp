//
//  Expression.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_Expression_hpp
#define Model_Expression_hpp
#include <string>
using std::string;

namespace isadt {
  /// \brief Expression in the Guard condition.
  class Expression {
  private:
    Expression* expressionA;
    Expression* expressionB;
    bool isSingleExpression;
    string binaryOp;

    string xml_value;

  public:
    Expression();
    Expression(string _value);

    Expression(Expression* _expressionA);
    Expression(Expression* _expressionA, Expression* _expressionB, string _binaryOp);
    Expression* getExpressionA();
    Expression* getExpressionB();
    string getBinaryOp();
    bool isSingledExpression();
  };
}

#endif /* Model_Expression_hpp */
