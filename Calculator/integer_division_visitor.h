//
//  integer_division_visitor.h
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef INTEGER_DIVISION_VISITOR_H_
#define INTEGER_DIVISION_VISITOR_H_

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"
#include "multiplication_expression.h"
#include "addition_expression.h"

class IntegerDivisionVisitor: public Visitor {
  private:
    // Storage for the first operand
    const Integer* operand_;
    
  public:
    // Constructor
    IntegerDivisionVisitor(const Integer*);
    
    // Visitor overrides
    MathElementPtr VisitInteger(const Integer*) const;
    MathElementPtr VisitDecimal(const Decimal*) const;
    MathElementPtr VisitFraction(const Fraction*) const;
    MathElementPtr VisitVariable(const Variable*) const;
    MathElementPtr VisitMultiplicationExpression(const MultiplicationExpression*) const;
    MathElementPtr VisitAdditionExpression(const AdditionExpression*) const;
};

#endif // INTEGER_DIVISION_VISITOR_H_
