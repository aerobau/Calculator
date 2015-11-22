//
//  fraction.h
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef FRACTION_H_
#define FRACTION_H_

#include "math_element.h"
#include "fraction_multiplication_visitor.h"
#include "fraction_division_visitor.h"
#include "fraction_addition_visitor.h"
#include "fraction_subtraction_visitor.h"

class Fraction: public MathElement {
  private:
    MathElementPtr numerator_;
    MathElementPtr denominator_;
    
  public:
    // Constructor
    Fraction(MathElementPtr, MathElementPtr);
    
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
    
    // Class specific methods
    
    // Accessors
    const MathElement* numerator() const;
    const MathElement* denominator() const;
    
    MathElementPtr ClonedNumerator() const;
    MathElementPtr ClonedDenominator() const;
    
    // Cloning Inversion
    MathElementPtr Invert() const;
};

#endif // FRACTION_H_
