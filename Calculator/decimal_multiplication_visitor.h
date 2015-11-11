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
#include "multiplication_expression.h"
#include "addition_expression.h"

class DecimalMultiplicationVisitor: public Visitor {
  private:
    // Storage for the first operand
    const Decimal* operand_;
    
    // Visitor specific helper
    MathElementPtr DecimalResult(const MathElement*, const MathElement*) const;
    
  public:
    // Constructor
    explicit DecimalMultiplicationVisitor(const Decimal*);
    
    // Visitor overrides
    MathElementPtr VisitInteger(const Integer*) const;
    MathElementPtr VisitDecimal(const Decimal*) const;
    MathElementPtr VisitFraction(const Fraction*) const;
    MathElementPtr VisitVariable(const Variable*) const;
    MathElementPtr VisitMultiplicationExpression(const MultiplicationExpression*) const;
    MathElementPtr VisitAdditionExpression(const AdditionExpression*) const;
};

#endif // DECIMAL_MULTIPLICATION_VISITOR_H_
