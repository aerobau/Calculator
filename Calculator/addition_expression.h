//
//  addition_expression.hpp
//  Calculator
//
//  Created by Alexander Robau on 11/4/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef ADDITION_EXPRESSION_H_
#define ADDITION_EXPRESSION_H_

#include "math_element.h"

class AdditionExpression : public MathElement {
private:
    // Vector representing the expression elements
    std::vector<MathElementPtr> elements_;
    
public:
    // Constructor
    explicit AdditionExpression(std::vector<MathElementPtr>);
    AdditionExpression(MathElementPtr, MathElementPtr);
    
    
    // MathElement overrides//
    
    // Visitor factory methods
    Visitor* CreateMultiplicationVisitor() const;
    Visitor* CreateDivisionVisitor() const;
    Visitor* CreateAdditionVisitor() const;
    Visitor* CreateSubtractionVisitor() const;
    EqualityVisitor* CreateEqualityVisitor() const;
    
    // Visitor acception methods
    MathElementPtr Accept(const Visitor*) const;
    bool Accept(const EqualityVisitor*) const;
    
    // Common value methods
    double DoubleValue() const;
    std::string ToString() const;
    
    // Cloning method
    MathElementPtr Clone() const;
    
    // Class specific functions //
    const std::vector<MathElementPtr>* elements() const;
    std::vector<MathElementPtr> ClonedElements() const;
    std::size_t NumberOfElements() const;
};

#endif // ADDITION_EXPRESSION_H_
