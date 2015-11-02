//
//  multiplication_expression_division_visitor.hpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef MULTIPLICATION_EXPRESSION_DIVISION_VISITOR_H_
#define MULTIPLICATION_EXPRESSION_DIVISION_VISITOR_H_

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"
#include "multiplication_expression.h"

class MultiplicationExpressionDivisionVisitor : public Visitor {
private:
    // Storage for the first operand
    const MultiplicationExpression* operand_;
    
public:
    // Constructor
    MultiplicationExpressionDivisionVisitor(const MultiplicationExpression*);
    
    // Visitor overrides
    MathElementPtr VisitInteger(const Integer*) const;
    MathElementPtr VisitDecimal(const Decimal*) const;
    MathElementPtr VisitFraction(const Fraction*) const;
    MathElementPtr VisitVariable(const Variable*) const;
    MathElementPtr VisitMultiplicationExpression(const MultiplicationExpression*) const;
};

#endif // MULTIPLICATION_EXPRESSION_DIVISION_VISITOR_H_
