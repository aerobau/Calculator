//
//  decimal.h
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef DECIMAL_H_
#define DECIMAL_H_

#include "math_element.h"
#include "decimal_multiplication_visitor.h"
#include "decimal_division_visitor.h"
#include "decimal_addition_visitor.h"
#include "decimal_subtraction_visitor.h"

class Decimal: public MathElement {
  private:
    double value_;
    
  public:
    // Constructor
    explicit Decimal(double);
    
    // MathElement overrides
    Visitor* CreateMultiplicationVisitor() const;
    Visitor* CreateDivisionVisitor() const;
    Visitor* CreateAdditionVisitor() const;
    Visitor* CreateSubtractionVisitor() const;
    EqualityVisitor* CreateEqualityVisitor() const;
    
    MathElementPtr Accept(const Visitor*) const;
    bool Accept(const EqualityVisitor*) const;
    
    double DoubleValue() const;
    std::string ToString() const;
    
    MathElementPtr Clone() const;
    
};

#endif // DECIMAL_H_
