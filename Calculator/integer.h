//
//  integer.h
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef INTEGER_H_
#define INTEGER_H_

#include "math_element.h"
#include "integer_multiplication_visitor.h"
#include "integer_division_visitor.h"
#include "integer_addition_visitor.h"
#include "integer_subtraction_visitor.h"

class Integer: public MathElement {
  private:
    int value_;
    
  public:
    // Constructor
    explicit Integer(int);
    
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
    
    // Class specific functions
    
    // Accessor for value
    int value() const;
};

#include "math_utilities.h"

#endif // INTEGER_H_
