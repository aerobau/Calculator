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
    VisitorPtr CreateMultiplicationVisitor() const;
    VisitorPtr CreateDivisionVisitor() const;
    VisitorPtr CreateAdditionVisitor() const;
    VisitorPtr CreateSubtractionVisitor() const;
    EqualityVisitorPtr CreateEqualityVisitor() const;
    
    // Visitor acception methods
    MathElementPtr Accept(const VisitorPtr) const;
    bool Accept(const EqualityVisitorPtr) const;
    
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
