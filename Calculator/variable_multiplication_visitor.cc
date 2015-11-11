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
    // Constructs and returns a new MultiplicationExpression
    return MathElementPtr(new MultiplicationExpression(operand_->Clone(), integer->Clone()));
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
    MathElementPtr result_numerator = Multiply(operand_, fraction->numerator());
    
    // Constructing and returning a new Fraction
    return MathElementPtr(new Fraction(std::move(result_numerator), fraction->ClonedDenominator()));
}

// Visit a Variable
MathElementPtr VariableMultiplicationVisitor::VisitVariable(const Variable* variable) const {
    if (Equal(operand_, variable)) {
        // TODO: return an exponent
        return MathElementPtr(nullptr);
    } else {
        // Create and return new MultiplicationExpression with the two variables
        return MathElementPtr(new MultiplicationExpression(operand_->Clone(), variable->Clone()));
    }
}

// Visit a MultiplicationExpression
MathElementPtr VariableMultiplicationVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    // Allow MultiplicationExpressionMultiplicationVisitor to handle (see VisitVariable(...))
    return Multiply(expression, operand_);
}

// Visit an AdditionExpression
MathElementPtr VariableMultiplicationVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    // Allow AdditionExpressionMultiplicationVisitor to handle (see VisitVariable(...))
    return Multiply(expression, operand_);
}