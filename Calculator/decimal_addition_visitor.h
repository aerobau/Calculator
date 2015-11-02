//
//  decimal_addition_visitor.hpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef DECIMAL_ADDITION_VISITOR_H_
#define DECIMAL_ADDITION_VISITOR_H_

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"

class DecimalAdditionVisitor: public Visitor {
  private:
    // Storage for the first operand
    const Decimal* operand_;
    
  public:
    // Constructor
    explicit DecimalAdditionVisitor(const Decimal*);
    
    // Visitor overrides
    MathElementPtr VisitInteger(const Integer*) const;
    MathElementPtr VisitDecimal(const Decimal*) const;
    MathElementPtr VisitFraction(const Fraction*) const;
    MathElementPtr VisitVariable(const Variable*) const;
    MathElementPtr VisitMultiplicationExpression(const MultiplicationExpression*) const;
};

#endif // DECIMAL_ADDITION_VISITOR_H_
