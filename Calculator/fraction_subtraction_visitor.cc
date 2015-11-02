//
//  fraction_subtraction_visitor.cc
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "fraction_subtraction_visitor.h"

FractionSubtractionVisitor::FractionSubtractionVisitor(const Fraction* operand)
    : operand_(operand) {}

MathElementPtr FractionSubtractionVisitor::VisitInteger(const Integer* integer) const {
    // Turn the integer into a fraction and subtract it from the fraction
    MathElementPtr integer_as_fraction =
        MathElementPtr(new Fraction(integer->Clone(), MathUtilities::One()));
    return integer_as_fraction->Accept(this);
}

MathElementPtr FractionSubtractionVisitor::VisitDecimal(const Decimal* decimal) const {
    // Finding the double difference and constructing and returning a Decimal
    double result_value = operand_->DoubleValue() - decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

MathElementPtr FractionSubtractionVisitor::VisitFraction(const Fraction* fraction) const {
    // Getting the common denominator by multiplying them.
    Visitor* operand_denominator_mult = operand_->denominator()->CreateMultiplicationVisitor();
    MathElementPtr common_denominator = fraction->denominator()->Accept(operand_denominator_mult);
    
    // Getting the first numerator by multiplying the operand numerator by the fraction denominator
    Visitor* operand_numerator_mult = operand_->numerator()->CreateMultiplicationVisitor();
    MathElementPtr first_numerator = fraction->denominator()->Accept(operand_numerator_mult);
    
    // Getting the second numerator bu multiplying the fraction numerator by the operand denominator
    MathElementPtr second_numerator = fraction->numerator()->Accept(operand_denominator_mult);
    
    // Subtracting the first and second numerators
    MathElementPtr sum_numerators = second_numerator->
        Accept(first_numerator->CreateSubtractionVisitor());
    
    // Constructing and returning a fraction
    return MathElementPtr(new Fraction(std::move(sum_numerators), std::move(common_denominator)));
}

MathElementPtr FractionSubtractionVisitor::VisitVariable(const Variable* variable) const {
    return MathElementPtr(nullptr);
}