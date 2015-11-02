//
//  fraction_subtraction_visitor.h
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef FRACTION_SUBTRACTION_VISITOR_H_
#define FRACTION_SUBTRACTION_VISITOR_H_

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"

class FractionSubtractionVisitor : public Visitor {
  private:
    // Storage for the first operand
    const Fraction* operand_;
    
  public:
    // Constructor
    FractionSubtractionVisitor(const Fraction*);
    
    // Visitor overrides
    MathElementPtr VisitInteger(const Integer*) const;
    MathElementPtr VisitDecimal(const Decimal*) const;
    MathElementPtr VisitFraction(const Fraction*) const;
    MathElementPtr VisitVariable(const Variable*) const;
};

#endif // FRACTION_SUBTRACTION_VISITOR_H_
