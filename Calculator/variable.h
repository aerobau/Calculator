//
//  variable.hpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef VARIABLE_H_
#define VARIABLE_H_

#include "math_element.h"
#include "variable_multiplication_visitor.h"
#include "variable_division_visitor.h"
#include "variable_addition_visitor.h"
#include "variable_subtraction_visitor.h"

class Variable : public MathElement {
  private:
    char representation_;
    
  public:
    // Constructor
    explicit Variable(char);
    
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
    
    // Accessor
    char representation() const;
};

#endif // VARIABLE_H_
