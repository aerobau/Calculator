//
//  integer_addition_visitor.cc
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "integer_addition_visitor.h"

IntegerAdditionVisitor::IntegerAdditionVisitor(const Integer* operand) : operand_(operand) {}


// VISITING FUNCTIONS //
// Visit various types and return the addition of the operand and the visited value

// Visit an Integer
MathElementPtr IntegerAdditionVisitor::VisitInteger(const Integer* integer) const {
    // Adding the integer values and constructing and returning an Integer
    int result_value = operand_->value() + integer->value();
    return MathElementPtr(new Integer(result_value));
}

// Visit a Decimal
MathElementPtr IntegerAdditionVisitor::VisitDecimal(const Decimal* decimal) const {
    // Adding the double values and constructing and returning a Decimal
    double result_value = operand_->DoubleValue() + decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr IntegerAdditionVisitor::VisitFraction(const Fraction* fraction) const {
    // Allow fraction to take care of it
    return Add(fraction, operand_);
}

// Visit a Variable
MathElementPtr IntegerAdditionVisitor::VisitVariable(const Variable* variable) const {
    return MathElementPtr(new AdditionExpression(operand_->Clone(), variable->Clone()));
}

// Visit an Exponent
MathElementPtr IntegerAdditionVisitor::VisitExponent(const Exponent* exponent) const {
    return MathElementPtr(new AdditionExpression(operand_->Clone(), exponent->Clone()));
}

// Visit a MultiplicationExpression
MathElementPtr IntegerAdditionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    return MathElementPtr(new AdditionExpression(operand_->Clone(), expression->Clone()));
}

// Visit an AdditionExpression
MathElementPtr IntegerAdditionVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    // Allow expression to take care of it
    return Add(expression, operand_);
}