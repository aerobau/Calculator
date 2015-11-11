//
//  decimal_multiplication_visitor.hpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef DECIMAL_MULTIPLICATION_VISITOR_H_
#define DECIMAL_MULTIPLICATION_VISITOR_H_

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"

class DecimalMultiplicationVisitor: public Visitor {
  private:
    // Storage for the first operand
    const Decimal* operand_;
    
  public:
    // Constructor
    explicit DecimalMultiplicationVisitor(const Decimal*);
    
    // Visitor overrides
    MathElementPtr VisitInteger(const Integer*) const;
    MathElementPtr VisitDecimal(const Decimal*) const;
    MathElementPtr VisitFraction(const Fraction*) const;
    MathElementPtr VisitVariable(const Variable*) const;
    MathElementPtr VisitMultiplicationExpression(const MultiplicationExpression*) const;
    
    // Visitor specific helper
    MathElementPtr DecimalResult(const MathElement*, const MathElement*) const;
};

#endif // DECIMAL_MULTIPLICATION_VISITOR_H_
