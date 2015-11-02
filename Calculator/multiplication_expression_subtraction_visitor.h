//
//  multiplication_expression_subtraction_visitor.hpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef MULTIPLICATION_EXPRESSION_SUBTRATION_VISITOR_H_
#define MULTIPLICATION_EXPRESSION_SUBTRATION_VISITOR_H_

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"
#include "multiplication_expression.h"

class MultiplicationExpressionSubtractionVisitor : public Visitor {
private:
    // Storage for the first operand
    const MultiplicationExpression* operand_;
    
public:
    MultiplicationExpressionSubtractionVisitor(const MultiplicationExpression*);
};

#endif // MULTIPLICATION_EXPRESSION_SUBTRATION_VISITOR_H_
