//
//  fraction_division_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "fraction_division_visitor.h"

// Constructor: sets the operand
FractionDivisionVisitor::FractionDivisionVisitor(const Fraction* operand) : operand_(operand) {}


// VISITING FUNCTIONS //
// Visit various types and return the division of the operand and the visited value

// Visit an Integer
MathElementPtr FractionDivisionVisitor::VisitInteger(const Integer* integer) const {
    return MultiplyByOperandDenominator(integer);
}

// Visit a Decimal
MathElementPtr FractionDivisionVisitor::VisitDecimal(const Decimal* decimal) const {
    // Calculating the double result value and constructing and returning a Decimal
    double result_value = operand_->DoubleValue() / decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr FractionDivisionVisitor::VisitFraction(const Fraction* fraction) const {
    // Invert the fraction, then multiply
    MathElementPtr inverted_fraction = fraction->Invert();
    return inverted_fraction->Accept(operand_->CreateMultiplicationVisitor());
}

// Visit a Variable
MathElementPtr FractionDivisionVisitor::VisitVariable(const Variable* variable) const {
    return MultiplyByOperandDenominator(variable);
}

// Visit a MultiplicationExpression
MathElementPtr FractionDivisionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    return MultiplyByOperandDenominator(expression);
}

MathElementPtr FractionDivisionVisitor::
MultiplyByOperandDenominator(const MathElement* element) const {
    // Calculating the result denominator by multiplying the operand denominator by the element
    MathElementPtr result_denominator = Multiply(operand_->denominator(), element);
    
    // Constructing and returning the Fraction
    return MathElementPtr(new Fraction(operand_->ClonedNumerator(), std::move(result_denominator)));
}