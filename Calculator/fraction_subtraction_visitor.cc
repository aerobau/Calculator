//
//  fraction_subtraction_visitor.cc
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "fraction_subtraction_visitor.h"

// -- PRIVATE FUNCTIONS -- //

MathElementPtr FractionAdditionVisitor::
MultiplyByDenominatorAndAdd(const MathElement* element) const {
    // Multiplying by the denominator and adding to the operand numerator
    MathElementPtr element_times_denominator = Multiply(element, operand_->denominator());
    MathElementPtr result_numerator = Subtract(operand_->numerator(),
                                               element_times_denominator.get());
    
    // Dividing the result to insure simplification
    return Divide(result_numerator.get(), operand_->denominator());
}

// +++ PUBLIC FUNCTIONS ++ //

FractionSubtractionVisitor::FractionSubtractionVisitor(const Fraction* operand)
    : operand_(operand) {}

MathElementPtr FractionSubtractionVisitor::VisitInteger(const Integer* integer) const {
    return MultiplyByDenominatorAndSubtract(integer);
}

MathElementPtr FractionSubtractionVisitor::VisitDecimal(const Decimal* decimal) const {
    // Finding the double difference and constructing and returning a Decimal
    double result_value = operand_->DoubleValue() - decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

MathElementPtr FractionSubtractionVisitor::VisitFraction(const Fraction* fraction) const {
    // Getting the common denominator by multiplying them.
    MathElementPtr common_denominator = Multiply(operand_->denominator(), fraction->denominator());
    
    // Cross multiplying to get the numerators
    MathElementPtr first_numerator = Multiply(operand_->numerator(), fraction->denominator());
    MathElementPtr second_numerator = Multiply(fraction->numerator(), operand_->denominator());
    
    // Subtracting the first and second numerators
    MathElementPtr difference_numerators = Subtract(first_numerator.get(), second_numerator.get());
    
    // Constructing and returning a fraction
    return Divide(difference_numerators.get(), common_denominator.get());
}

MathElementPtr FractionSubtractionVisitor::VisitVariable(const Variable* variable) const {
    return MultiplyByDenominatorAndSubtract(variable);
}

MathElementPtr FractionSubtractionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    return MultiplyByDenominatorAndSubtract(expression);
}

MathElementPtr FractionSubtractionVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    return MultiplyByDenominatorAndSubtract(expression);
}