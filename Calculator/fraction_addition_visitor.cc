//
//  fraction_addition_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "fraction_addition_visitor.h"

FractionAdditionVisitor::FractionAdditionVisitor(const Fraction* operand) : operand_(operand) {}


// VISITING FUNCTIONS //
// Visit various types and return the addition of the operand and the visited value

// Visit an Integer
MathElementPtr FractionAdditionVisitor::VisitInteger(const Integer* integer) const {
    // Making the integer a fraction and adding by passing the visitor to the accept for the created
    // fraction
    MathElementPtr integer_as_fraction =
        MathElementPtr(new Fraction(integer->Clone(), MathUtilities::One()));
    return integer_as_fraction->Accept(this);
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
    Visitor* operand_denominator_mult = operand_->denominator()->CreateMultiplicationVisitor();
    MathElementPtr common_denominator = fraction->denominator()->Accept(operand_denominator_mult);
    
    // Getting the first numerator by multiplying the operand numerator by the fraction denominator
    Visitor* operand_numerator_mult = operand_->numerator()->CreateMultiplicationVisitor();
    MathElementPtr first_numerator = fraction->denominator()->Accept(operand_numerator_mult);
    
    // Getting the second numerator bu multiplying the fraction numerator by the operand denominator
    MathElementPtr second_numerator = fraction->numerator()->Accept(operand_denominator_mult);
    
    // Adding the first and second numerators
    MathElementPtr sum_numerators = second_numerator->
        Accept(first_numerator->CreateAdditionVisitor());
    
    // Constructing and returning a fraction
    return MathElementPtr(new Fraction(std::move(sum_numerators), std::move(common_denominator)));
}

// Visit a Variable
MathElementPtr FractionAdditionVisitor::VisitVariable(const Variable* variable) const {
    // Making the variable into a fraction and returning the addition of it and the operand
    MathElementPtr variable_as_fraction =
        MathElementPtr(new Fraction(variable->Clone(), MathUtilities::One()));
    return variable_as_fraction->Accept(this);
}

// Visit a MultiplicationExpression
MathElementPtr FractionAdditionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    // Making the variable into a fraction and returning the addition of it and the operand
    MathElementPtr variable_as_fraction =
        MathElementPtr(new Fraction(expression->Clone(), MathUtilities::One()));
    return variable_as_fraction->Accept(this);
}