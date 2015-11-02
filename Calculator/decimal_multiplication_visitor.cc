//
//  decimal_multiplication_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "decimal_multiplication_visitor.h"

// Constructor: sets the operand
DecimalMultiplicationVisitor::DecimalMultiplicationVisitor(const Decimal* operand)
    : operand_(operand) {}


// VISITING FUNCTIONS //
// Visit various types and return the multiplication of the operand and the visited value

// Visit an integer
MathElementPtr DecimalMultiplicationVisitor::VisitInteger(const Integer* integer) const {
    // Getting the double value and constructing and returning a decimal
    double result_value = operand_->DoubleValue() * integer->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a decimal
MathElementPtr DecimalMultiplicationVisitor::VisitDecimal(const Decimal* decimal) const {
    // Getting the double value and constructing and returning a decimal
    double result_value = operand_->DoubleValue() * decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a fraction
MathElementPtr DecimalMultiplicationVisitor::VisitFraction(const Fraction* fraction) const {
    // Getting the double value and constructing and returning a decimal
    double result_value = operand_->DoubleValue() * fraction->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a variable
MathElementPtr DecimalMultiplicationVisitor::VisitVariable(const Variable* variable) const {
    // Getting the double value and constructing and returning a decimal
    double result_value = operand_->DoubleValue() * variable->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a MultiplicationExpression
MathElementPtr DecimalMultiplicationVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    // Getting the double value and constructing and returning a decimal
    double result_value = operand_->DoubleValue() * expression->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}