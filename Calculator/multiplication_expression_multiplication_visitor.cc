//
//  multiplication_expression_multiplication_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "multiplication_expression_multiplication_visitor.h"

// Constructor: sets the operand
MultiplicationExpressionMultiplicationVisitor::
MultiplicationExpressionMultiplicationVisitor(const MultiplicationExpression* operand)
    : operand_(operand) {}

// VISITING FUNCTIONS //
// Visit various types and return the multiplication of the operand and the visited value

// Visit an Integer
MathElementPtr MultiplicationExpressionMultiplicationVisitor::
VisitInteger(const Integer* integer) const {
    // Constructing and returning a multiplciation expression witht he included integer
    return AddElementToOperand(integer);
}

// Visit a Decimal
MathElementPtr MultiplicationExpressionMultiplicationVisitor::
VisitDecimal(const Decimal* decimal) const {
    // Getting the double result value and constructing and returning a new Decimal
    double result_value = operand_->DoubleValue() * decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr MultiplicationExpressionMultiplicationVisitor::
VisitFraction(const Fraction* fraction) const {
    // Getting the result's numerator by multiplying the operand by the fraction's numerator
    MathElementPtr result_numerator = Multiply(operand_, fraction->numerator());
    
    // Constructing and returning a new Fraction
    return MathElementPtr(new Fraction(std::move(result_numerator), fraction->ClonedDenominator()));
}

// Visit a Variable
MathElementPtr MultiplicationExpressionMultiplicationVisitor::
VisitVariable(const Variable* variable) const {
    // Constructing and returning a multiplciation expression with the included variable
    return AddElementToOperand(variable);
}

// Visit an Exponent
MathElementPtr MultiplicationExpressionMultiplicationVisitor::
VisitExponent(const Exponent* exponent) const {
    // Allow Exponent to handle
    return Multiply(exponent, operand_);
}

// Visit a MultiplicationExpression
MathElementPtr MultiplicationExpressionMultiplicationVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    if (Equal(operand_, expression)) {
        return MathElementPtr(new Exponent(operand_->Clone(), MathUtilities::Two()));
    } else {
        return AddElementsToOperand(expression->elements());
    }
}

// Visit an AdditionExpression
MathElementPtr MultiplicationExpressionMultiplicationVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    return AddElementToOperand(expression);
}

// Add an element to the operand elements and return a new MultiplicationExpression
MathElementPtr MultiplicationExpressionMultiplicationVisitor::
AddElementToOperand(const MathElement* element) const {
    // Getting the Cloned elements and adding on the element to the operand's
    std::vector<MathElementPtr> cloned_elements = operand_->ClonedElements();
    cloned_elements.push_back(element->Clone());
    
    // Returning the new MultiplicationExpression with the added element
    return MathElementPtr(new MultiplicationExpression(std::move(cloned_elements)));
}

// Add a vector of elements to the operand elements and return a new MultiplicationExpression
MathElementPtr MultiplicationExpressionMultiplicationVisitor::
AddElementsToOperand(const std::vector<MathElementPtr>* elements) const {
    // Getting the elements from the operand and expression
    std::vector<MathElementPtr> cloned_elements = operand_->ClonedElements();
    
    // Adding all of the elements from the expression to the operand cloned elements
    for (int i = 0; i < elements->size(); ++i) {
        cloned_elements.push_back(elements->at(i)->Clone());
    }
    return MathElementPtr(new MultiplicationExpression(std::move(cloned_elements)));
}

