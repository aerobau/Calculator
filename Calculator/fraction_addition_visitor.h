//
//  fraction_addition_visitor.hpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef FRACTION_ADDITION_VISITOR_H_
#define FRACTION_ADDITION_VISITOR_H_

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"

class FractionAdditionVisitor : public Visitor {
  private:
    // Storage for the first operand
    const Fraction* operand_;
    
    MathElementPtr MultiplyByDenominatorAndAdd(const MathElement*) const;
    
  public:
    // Constructor
    FractionAdditionVisitor(const Fraction*);
    
    // Visitor overrides
    MathElementPtr VisitInteger(const Integer*) const;
    MathElementPtr VisitDecimal(const Decimal*) const;
    MathElementPtr VisitFraction(const Fraction*) const;
    MathElementPtr VisitVariable(const Variable*) const;
    MathElementPtr VisitExponent(const Exponent*) const;
    MathElementPtr VisitMultiplicationExpression(const MultiplicationExpression*) const;
    MathElementPtr VisitAdditionExpression(const AdditionExpression*) const;
};

#endif // FRACTION_ADDITION_VISITOR_H_
