//
//  fraction_multiplication_visitor.h
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef FRACTION_MULTIPLICATION_VISITOR_H
#define FRACTION_MULTIPLICATION_VISITOR_H

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"
#include "multiplication_expression.h"
#include "addition_expression.h"

class FractionMultiplicationVisitor : public Visitor {
  private:
    // Storage for the first operand
    const Fraction* operand_;
    
  public:
    // Constructor
    FractionMultiplicationVisitor(const Fraction*);
    
    // Visitor overrides
    MathElementPtr VisitInteger(const Integer*) const;
    MathElementPtr VisitDecimal(const Decimal*) const;
    MathElementPtr VisitFraction(const Fraction*) const;
    MathElementPtr VisitVariable(const Variable*) const;
    MathElementPtr VisitMultiplicationExpression(const MultiplicationExpression*) const;
    MathElementPtr VisitAdditionExpression(const AdditionExpression*) const;
};

#endif // FRACTION_MULTIPLICATION_VISITOR_H_
