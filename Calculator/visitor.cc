//
//  visitor.cc
//  Calculator
//
//  Created by Alexander Robau on 11/10/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "visitor.h"
#include "math_element.h"

// Multiply two MathElements by having the second accept the MultiplicationVisitor of the first
MathElementPtr Visitor::Multiply(const MathElement *first, const MathElement *second) const {
    return second->Accept(first->CreateMultiplicationVisitor());
}

// Divide two MathElements by having the second accept the DivisionVisitor of the first
MathElementPtr Visitor::Divide(const MathElement* first, const MathElement* second) const {
    return second->Accept(first->CreateDivisionVisitor());
}

// Add two MathElements by having the second accept the AdditionVisitor of the first
MathElementPtr Visitor::Add(const MathElement* first, const MathElement* second) const {
    return second->Accept(first->CreateAdditionVisitor());
}

// Subtract two MathElements by having the second accept the SubtractionVisitor of the first
MathElementPtr Visitor::Subtract(const MathElement* first, const MathElement* second) const {
    return second->Accept(first->CreateSubtractionVisitor());
}