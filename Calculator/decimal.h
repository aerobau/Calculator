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
    VisitorPtr CreateMultiplicationVisitor() const;
    VisitorPtr CreateDivisionVisitor() const;
    VisitorPtr CreateAdditionVisitor() const;
    VisitorPtr CreateSubtractionVisitor() const;
    EqualityVisitorPtr CreateEqualityVisitor() const;
    
    MathElementPtr Accept(const VisitorPtr) const;
    bool Accept(const EqualityVisitorPtr) const;
    MathElementPtr Exchange(const MathElement*, const MathElement*) const;
    
    double DoubleValue() const;
    std::string ToString() const;
    
    MathElementPtr Clone() const;
    
};

#endif // DECIMAL_H_
