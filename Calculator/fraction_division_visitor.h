//
//  fraction_division_visitor.hpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef FRACTION_DIVISION_VISITOR_H_
#define FRACTION_DIVISION_VISITOR_H_

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"

class FractionDivisionVisitor : public Visitor {
  private:
    // Storage for the first operand
    const Fraction* operand_;
    
    // Class specific function
    MathElementPtr MultiplyByOperandDenominator(const MathElement*) const;
    
  public:
    // Constructor
    FractionDivisionVisitor(const Fraction*);
    
    // Visitor overrides
    MathElementPtr VisitInteger(const Integer*) const;
    MathElementPtr VisitDecimal(const Decimal*) const;
    MathElementPtr VisitFraction(const Fraction*) const;
    MathElementPtr VisitVariable(const Variable*) const;
    MathElementPtr VisitMultiplicationExpression(const MultiplicationExpression*) const;
    MathElementPtr VisitAdditionExpression(const AdditionExpression*) const;
};

#endif // FRACTION_DIVISION_VISITOR_H_
