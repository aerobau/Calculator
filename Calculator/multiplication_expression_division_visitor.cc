//
//  multiplication_expression_division_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "multiplication_expression_division_visitor.h"

MultiplicationExpressionDivisionVisitor::
MultiplicationExpressionDivisionVisitor(const MultiplicationExpression* operand)
    : operand_(operand) {}


// VISITING FUNCTIONS //
// Visit various types and return the division of the operand and the visited value

// Visit an Integer
MathElementPtr MultiplicationExpressionDivisionVisitor::VisitInteger(const Integer* integer) const {
    // Construct and return a new Fraction
    return MathElementPtr(new Fraction(operand_->Clone(), integer->Clone()));
}

// Visit a Decimal
MathElementPtr MultiplicationExpressionDivisionVisitor::VisitDecimal(const Decimal* decimal) const {
    // Calculate the double value and construct and return a new decimal
    double result_value = operand_->DoubleValue() / decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr MultiplicationExpressionDivisionVisitor::
VisitFraction(const Fraction* fraction) const {
    // Multiply by the denominator, make the numerator the denominator of new constructed fraction
    MathElementPtr result_numerator = fraction->denominator()->Accept(this);
    return MathElementPtr(new Fraction(std::move(result_numerator), fraction->ClonedNumerator()));
}

// Visit a Variable
MathElementPtr MultiplicationExpressionDivisionVisitor::
VisitVariable(const Variable* variable) const {
    // Construct and return a new Fraction
    return MathElementPtr(new Fraction(operand_->Clone(), variable->Clone()));
}

// Visit a MultiplicationExpression
MathElementPtr MultiplicationExpressionDivisionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    // Construct and return a new Fraction
    return MathElementPtr(new Fraction(operand_->Clone(), expression->Clone()));
}