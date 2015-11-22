//
//  exponent_division_visitor.hpp
//  Calculator
//
//  Created by Alexander Robau on 11/21/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef EXPONENT_DIVISION_VISITOR_H_
#define EXPONENT_DIVISION_VISITOR_H_

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"
#include "exponent.h"
#include "multiplication_expression.h"
#include "addition_expression.h"

class ExponentDivisionVisitor : public Visitor {
private:
    const Exponent* operand_;
    
    MathElementPtr CheckBaseDivide(const MathElement*) const;
    
public:
    ExponentDivisionVisitor(const Exponent*);
    
    MathElementPtr VisitInteger(const Integer*) const;
    MathElementPtr VisitDecimal(const Decimal*) const;
    MathElementPtr VisitFraction(const Fraction*) const;
    MathElementPtr VisitVariable(const Variable*) const;
    MathElementPtr VisitExponent(const Exponent*) const;
    MathElementPtr VisitMultiplicationExpression(const MultiplicationExpression*) const;
    MathElementPtr VisitAdditionExpression(const AdditionExpression*) const;
};

#endif // EXPONENT_DIVISION_VISITOR_H_
