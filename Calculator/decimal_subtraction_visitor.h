//
//  decimal_subtraction_visitor.hpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef DECIMAL_SUBTRACTION_VISITOR_H_
#define DECIMAL_SUBTRACTION_VISITOR_H_

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"

class DecimalSubtractionVisitor: public Visitor {
  private:
    // Storage for the first operand
    const Decimal* operand_;
    
  public:
    // Constructor
    explicit DecimalSubtractionVisitor(const Decimal*);
    
    // Visitor overrides
    MathElementPtr VisitInteger(const Integer*) const;
    MathElementPtr VisitDecimal(const Decimal*) const;
    MathElementPtr VisitFraction(const Fraction*) const;
    MathElementPtr VisitVariable(const Variable*) const;
};

#endif // DECIMAL_SUBTRACTION_VISITOR_H_
