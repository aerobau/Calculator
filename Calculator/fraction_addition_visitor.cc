//
//  fraction_addition_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "fraction_addition_visitor.h"

// -- PRIVATE FUNCTIONS -- //

MathElementPtr FractionAdditionVisitor::
MultiplyByDenominatorAndAdd(const MathElement* element) const {
    // Multiplying by the denominator and adding to the operand numerator
    MathElementPtr element_times_denominator = Multiply(element, operand_->denominator());
    MathElementPtr result_numerator = Add(operand_->numerator(), element_times_denominator.get());
    
    // Dividing the result to insure simplification
    return Divide(result_numerator.get(), operand_->denominator());
}

// ++ PUBLIC FUNCTIONS ++ //

FractionAdditionVisitor::FractionAdditionVisitor(const Fraction* operand) : operand_(operand) {}


// VISITING FUNCTIONS //
// Visit various types and return the addition of the operand and the visited value

// Visit an Integer
MathElementPtr FractionAdditionVisitor::VisitInteger(const Integer* integer) const {
    return MultiplyByDenominatorAndAdd(integer);
}

// Visit a Decimal
MathElementPtr FractionAdditionVisitor::VisitDecimal(const Decimal* decimal) const {
    // Calculating the double result value and constructing and returning a new Decimal
    double result_value = operand_->DoubleValue() + decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr FractionAdditionVisitor::VisitFraction(const Fraction* fraction) const {
    // Getting the common denominator by multiplying them.
    MathElementPtr common_denominator = Multiply(operand_->denominator(), fraction->denominator());
    
    // Cross multiplication to find the numerators that need to be added
    MathElementPtr first_numerator = Multiply(operand_->numerator(), fraction->denominator());
    MathElementPtr second_numerator = Multiply(fraction->numerator(), operand_->denominator());
    
    // Adding the first and second numerators
    MathElementPtr result_numerator = Add(first_numerator.get(), second_numerator.get());
    
    // Dividing the result numerator by the denominator to insure simplification
    return Divide(result_numerator.get(), common_denominator.get());
}

// Visit a Variable
MathElementPtr FractionAdditionVisitor::VisitVariable(const Variable* variable) const {
    return MultiplyByDenominatorAndAdd(variable);
}

// Visit a MultiplicationExpression
MathElementPtr FractionAdditionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    return MultiplyByDenominatorAndAdd(expression);
}

// Visit and AdditionExpression
MathElementPtr FractionAdditionVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    // Allow expression to handle
    return Add(expression, operand_);
}