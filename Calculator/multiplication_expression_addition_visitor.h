//
//  multiplication_expression_addition_visitor.hpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef MULTIPLICATION_EXPRESSION_ADDITION_VISITOR_H_
#define MULTIPLICATION_EXPRESSION_ADDITION_VISITOR_H_

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"
#include "multiplication_expression.h"

class MultiplicationExpressionAdditionVisitor : public Visitor {
private:
    // Storage for the first operand
    const MultiplicationExpression* operand_;
    
public:
    MultiplicationExpressionAdditionVisitor(const MultiplicationExpression*);
    
    // TODO: Create Visitor functions (requires AdditionExpression)
};

#endif // MULTIPLICATION_EXPRESSION_ADDITION_VISITOR_H_