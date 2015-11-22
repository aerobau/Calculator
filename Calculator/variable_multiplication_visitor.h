//
//  VariableMultiplicationVisitor.hpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef VARIABLE_MULTIPLICATION_VISITOR_H_
#define VARIABLE_MULTIPLICATION_VISITOR_H_

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"
#include "exponent.h"
#include "multiplication_expression.h"
#include "addition_expression.h"


class VariableMultiplicationVisitor : public Visitor {
private:
    const Variable* operand_;
    
public:
    VariableMultiplicationVisitor(const Variable*);
    
    MathElementPtr VisitInteger(const Integer*) const;
    MathElementPtr VisitDecimal(const Decimal*) const;
    MathElementPtr VisitFraction(const Fraction*) const;
    MathElementPtr VisitVariable(const Variable*) const;
    MathElementPtr VisitExponent(const Exponent*) const;
    MathElementPtr VisitMultiplicationExpression(const MultiplicationExpression*) const;
    MathElementPtr VisitAdditionExpression(const AdditionExpression*) const;
};

#endif // VARIABLE_MUTLIPLICATION_VISITOR_H_
