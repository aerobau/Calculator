//
//  decimal_division_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "decimal_division_visitor.h"

// Constructor: sets the operand
DecimalDivisionVisitor::DecimalDivisionVisitor(const Decimal* operand) : operand_(operand) {}

// VISITING FUNCTIONS //
// Visit various types and return the division of the operand and the visited value

// Visit an integer
MathElementPtr DecimalDivisionVisitor::VisitInteger(const Integer* integer) const {
    // Dividing the double values, constructing and returning a Decimal
    double result_value = operand_->DoubleValue() / integer->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Decimal
MathElementPtr DecimalDivisionVisitor::VisitDecimal(const Decimal* decimal) const {
    // Dividing the double values, constructing and returning a Decimal
    double result_value = operand_->DoubleValue() / decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr DecimalDivisionVisitor::VisitFraction(const Fraction* fraction) const {
    // Dividing the double values, constructing and returning a Decimal
    double result_value = operand_->DoubleValue() / fraction->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Variable
MathElementPtr DecimalDivisionVisitor::VisitVariable(const Variable* variable) const {
    // Dividing the double values, constructing and returning a Decimal
    double result_value = operand_->DoubleValue() / variable->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

MathElementPtr DecimalDivisionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    // Dividing the double values, constructing and returning a Decimal
    double result_value = operand_->DoubleValue() / expression->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}