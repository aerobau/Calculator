//
//  integer_multiplication_visitor.cc
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "integer_multiplication_visitor.h"

// Constructor: sets the operand
IntegerMultiplicationVisitor::IntegerMultiplicationVisitor(const Integer* operand)
    : operand_(operand) {}


// VISITING FUNCTIONS //
// Visit various types and return the multiplication of the operand and the visited value

// Visit an integer
MathElementPtr IntegerMultiplicationVisitor::VisitInteger(const Integer* integer) const {
    // Multiplying the two integers and constructing and returning an Integer
    int result_value = operand_->value() * integer->value();
    return MathElementPtr(new Integer(result_value));
}

// Visit a decimal
MathElementPtr IntegerMultiplicationVisitor::VisitDecimal(const Decimal* decimal) const {
    // Multiplying the double values and constructing and returning a Decimal
    double result_value = operand_->DoubleValue() * decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a fraction
MathElementPtr IntegerMultiplicationVisitor::VisitFraction(const Fraction* fraction) const {
    // Utilizing the multiplication visitor to multiply the numerator by the operand
    MathElementPtr result_numerator = Multiply(operand_, fraction->numerator());
    
    // Constructing and returning a Fraction
    return MathElementPtr(new Fraction(std::move(result_numerator), fraction->ClonedDenominator()));
}

// Visit a variable
MathElementPtr IntegerMultiplicationVisitor::VisitVariable(const Variable* variable) const {
    // Creating a vector of elements witht he operand and the variable
    std::vector<MathElementPtr> elements;
    elements.push_back(operand_->Clone());
    elements.push_back(variable->Clone());
    
    // Constrcuting and returning a new MultiplcationExpression
    return MathElementPtr(new MultiplicationExpression(std::move(elements)));
}

// Visit an Exponent
MathElementPtr IntegerMultiplicationVisitor::VisitExponent(const Exponent* exponent) const {
    // Allow Exponent to take care of it
    return Multiply(exponent, operand_);
}

// Visit a MultiplicationExpression
MathElementPtr IntegerMultiplicationVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    // Allow MultiplicationExpressionMultiplicationVisitor to handle (see VisitInteger(...) method)
    return Multiply(expression, operand_);
}

MathElementPtr IntegerMultiplicationVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    // Allow AdditionExpressionMultiplicationVisitor to handle (see VisitInteger(...) method)
    return Multiply(expression, operand_);
}