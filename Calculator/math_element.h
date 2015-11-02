//
//  math_element.h
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef MATH_ELEMENT_H_
#define MATH_ELEMENT_H_

#include "visitor.h"
#include "equality_visitor.h"
#include <sstream>

class MathElement {
  public:
    virtual Visitor* CreateMultiplicationVisitor() const = 0;
    virtual Visitor* CreateDivisionVisitor() const = 0;
    virtual Visitor* CreateAdditionVisitor() const = 0;
    virtual Visitor* CreateSubtractionVisitor() const = 0;
    virtual EqualityVisitor* CreateEqualityVisitor() const = 0;
    
    virtual MathElementPtr Accept(const Visitor*) const = 0;
    virtual bool Accept(const EqualityVisitor*) const = 0;
    
    virtual double DoubleValue() const = 0;
    virtual std::string ToString() const = 0;
    
    virtual MathElementPtr Clone() const = 0;
};

#endif // MATH_ELEMENT_H_
