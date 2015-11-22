//
//  exponent_multiplication_visitor.hpp
//  Calculator
//
//  Created by Alexander Robau on 11/21/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef EXPONENT_MULTIPLICATION_VISITOR_H_
#define EXPONENT_MULTIPLICATION_VISITOR_H_

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"
#include "exponent.h"
#include "multiplication_expression.h"
#include "addition_expression.h"

class ExponentMultiplicationVisitor : public Visitor {
private:
    const Exponent* operand_;
    
    MathElementPtr CheckBaseMultiply(const MathElement*) const;
    
public:
    ExponentMultiplicationVisitor(const Exponent*);
    
    MathElementPtr VisitInteger(const Integer*) const;
    MathElementPtr VisitDecimal(const Decimal*) const;
    MathElementPtr VisitFraction(const Fraction*) const;
    MathElementPtr VisitVariable(const Variable*) const;
    MathElementPtr VisitExponent(const Exponent*) const;
    MathElementPtr VisitMultiplicationExpression(const MultiplicationExpression*) const;
    MathElementPtr VisitAdditionExpression(const AdditionExpression*) const;
};

#endif // EXPONENT_MULTIPLICATION_VISITOR_H_
