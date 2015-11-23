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
    
    // Class specific methods
    
    // Accessor
    char representation() const;
};

#endif // VARIABLE_H_
