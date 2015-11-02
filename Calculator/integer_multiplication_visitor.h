//
//  integer_multiplication_visitor.h
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef INTEGER_MULTIPLICATION_VISITOR_H_
#define INTEGER_MULTIPLICATION_VISITOR_H_

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"

class IntegerMultiplicationVisitor: public Visitor {
  private:
    // Storage for the first operand
    const Integer* operand_;
    
  public:
    // Constructor
    explicit IntegerMultiplicationVisitor(const Integer*);
    
    // Visitor overrides
    MathElementPtr VisitInteger(const Integer*) const;
    MathElementPtr VisitDecimal(const Decimal*) const;
    MathElementPtr VisitFraction(const Fraction*) const;
    MathElementPtr VisitVariable(const Variable*) const;
    MathElementPtr VisitMultiplicationExpression(const MultiplicationExpression*) const;
};

#endif // INTEGER_MULTIPLICATION_VISITOR_H_
