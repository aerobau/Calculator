//
//  integer_subtraction_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "integer_subtraction_visitor.h"

// -- NEGATIVE FUNCTIONS -- //

MathElementPtr IntegerSubtractionVisitor::AddNegation(const MathElement* element) const {
    MathElementPtr negation = Multiply(MathUtilities::NegativeOne().get(), element);
    return Add(operand_, negation.get());
}

// ++ PUBLIC FUNCTIONS ++ //

// Constructor
IntegerSubtractionVisitor::IntegerSubtractionVisitor(const Integer* operand) : operand_(operand) {}


// VISITING FUNCTIONS //
// Visit various types and return the addition of the operand and the visited value

// Visit an Integer
MathElementPtr IntegerSubtractionVisitor::VisitInteger(const Integer* integer) const {
    // Finding the difference of the two integers and constructing and returning an Integer
    int result_value = operand_->value() - integer->value();
    return MathElementPtr(new Integer(result_value));
}

// Visit a Decimal
MathElementPtr IntegerSubtractionVisitor::VisitDecimal(const Decimal* decimal) const {
    // Finding the double difference and constructing and returning a Decimal
    double result_value = operand_->DoubleValue() - decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr IntegerSubtractionVisitor::VisitFraction(const Fraction* fraction) const {
    // Making the integer into a fraction and subtracting the fraction from it.
    MathElementPtr integer_as_fraction =
        MathElementPtr(new Fraction(operand_->Clone(), MathUtilities::One()));
    return fraction->Accept(integer_as_fraction->CreateSubtractionVisitor());
}

// Visit a Variable
MathElementPtr IntegerSubtractionVisitor::VisitVariable(const Variable* variable) const {
    return AddNegation(variable);
}

// Visit a MultiplicationExpression
MathElementPtr IntegerSubtractionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    return AddNegation(expression);
}

MathElementPtr IntegerSubtractionVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    return AddNegation(expression);
}