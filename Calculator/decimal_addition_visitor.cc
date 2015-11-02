//
//  decimal_addition_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "decimal_addition_visitor.h"

DecimalAdditionVisitor::DecimalAdditionVisitor(const Decimal* operand) : operand_(operand) {}

// VISITING FUNCTIONS //
// Visit various types and return the addition of the operand and the visited value

// Visit an Integer
MathElementPtr DecimalAdditionVisitor::VisitInteger(const Integer* integer) const {
    // Adding the double values and constructing and returning a Decimal
    double result_value = operand_->DoubleValue() + integer->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Decimal
MathElementPtr DecimalAdditionVisitor::VisitDecimal(const Decimal* decimal) const {
    // Adding the double values and constructing and returning a Decimal
    double result_value = operand_->DoubleValue() + decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr DecimalAdditionVisitor::VisitFraction(const Fraction* fraction) const {
    // Adding the double values and constructing and returning a Decimal
    double result_value = operand_->DoubleValue() + fraction->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Variable
MathElementPtr DecimalAdditionVisitor::VisitVariable(const Variable* variable) const {
    // Adding the double values and constructing and returning a Decimal
    double result_value = operand_->DoubleValue() + variable->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a MultiplicationExpression
MathElementPtr DecimalAdditionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    // Adding the double values and constructing and returning a Decimal
    double result_value = operand_->DoubleValue() + expression->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}