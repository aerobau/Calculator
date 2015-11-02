//
//  VariableMultiplicationVisitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "variable_multiplication_visitor.h"

// Constructor: sets the operand
VariableMultiplicationVisitor::VariableMultiplicationVisitor(const Variable* operand)
    : operand_(operand) {}

// VISITING FUNCTIONS //
// Visit various types and return the multiplication of the operand and the visited value

// Visit an Integer
MathElementPtr VariableMultiplicationVisitor::VisitInteger(const Integer* integer) const {
    // Creating the vector of elements that will be used to construct a multiplication expression
    std::vector<MathElementPtr> elements;
    elements.push_back(operand_->Clone());
    elements.push_back(integer->Clone());
    
    // Constructs and returns a new MultiplicationExpression
    return MathElementPtr(new MultiplicationExpression(std::move(elements)));
}

// Visit a Decimal
MathElementPtr VariableMultiplicationVisitor::VisitDecimal(const Decimal* decimal) const {
    // Calculate the double result and construct and return a new Decimal
    double result_value = operand_->DoubleValue() * decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr VariableMultiplicationVisitor::VisitFraction(const Fraction* fraction) const {
    // Getting the new numerator by multiplying the fraction numerator with the variable
    MathElementPtr result_numerator = fraction->numerator()->Accept(this);
    
    // Constructing and returning a new Fraction
    return MathElementPtr(new Fraction(std::move(result_numerator), fraction->ClonedDenominator()));
}

// Visit a Variable
MathElementPtr VariableMultiplicationVisitor::VisitVariable(const Variable* variable) const {
    if (variable->Accept(operand_->CreateEqualityVisitor())) {
        // TODO: return an exponent
        return MathElementPtr(nullptr);
    } else {
        // Create and return new MultiplicationExpression with the two variables
        std::vector<MathElementPtr> elements;
        elements.push_back(operand_->Clone());
        elements.push_back(variable->Clone());
        return MathElementPtr(new MultiplicationExpression(std::move(elements)));
    }
}

// Visit a MultiplicationExpression
MathElementPtr VariableMultiplicationVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    // Get the cloned elements, add the variable to them, and return a new MultiplicationExpression
    std::vector<MathElementPtr> cloned_elements = expression->ClonedElements();
    cloned_elements.push_back(operand_->Clone());
    return MathElementPtr(new MultiplicationExpression(std::move(cloned_elements)));
}