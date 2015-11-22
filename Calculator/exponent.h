//
//  exponent.hpp
//  Calculator
//
//  Created by Alexander Robau on 11/21/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef EXPONENT_H_
#define EXPONENT_H_

#include "math_element.h"

class Exponent : public MathElement {
private:
    MathElementPtr base_;
    MathElementPtr exponent_;
public:
    Exponent(MathElementPtr, MathElementPtr);
    
    VisitorPtr CreateMultiplicationVisitor() const;
    VisitorPtr CreateDivisionVisitor() const;
    VisitorPtr CreateAdditionVisitor() const;
    VisitorPtr CreateSubtractionVisitor() const;
    EqualityVisitorPtr CreateEqualityVisitor() const;
    
    MathElementPtr Accept(const VisitorPtr) const;
    bool Accept(const EqualityVisitorPtr) const;
    
    double DoubleValue() const;
    std::string ToString() const;
    
    MathElementPtr Clone() const;
    
    // Class specific functions
    
    const MathElement* base() const;
    const MathElement* exponent() const;
    
    MathElementPtr ClonedBase() const;
    MathElementPtr ClonedExponent() const;
};

#endif // EXPONENT_H_

