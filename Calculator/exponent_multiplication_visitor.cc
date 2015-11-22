//
//  exponent_multiplication_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/21/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "exponent_multiplication_visitor.h"

// -- PRIVATE FUNCTIONS -- //

MathElementPtr ExponentMultiplicationVisitor::CheckBaseMultiply(const MathElement* element) const {
    if (Equal(operand_->base(), element)) {
        MathElementPtr exponent_plus_one = Add(operand_->exponent(), MathUtilities::One().get());
        return MathElementPtr(new Exponent(operand_->ClonedBase(), exponent_plus_one->Clone()));
    } else {
        return MathElementPtr(new MultiplicationExpression(operand_->Clone(), element->Clone()));
    }
}

// ++ PUBLIC FUNCTIONS ++ //

ExponentMultiplicationVisitor::ExponentMultiplicationVisitor(const Exponent* operand)
    : operand_(operand) {}

MathElementPtr ExponentMultiplicationVisitor::VisitInteger(const Integer* integer) const {
    return CheckBaseMultiply(integer);
}

MathElementPtr ExponentMultiplicationVisitor::VisitDecimal(const Decimal* decimal) const {
    double result_value = operand_->DoubleValue() * decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

MathElementPtr ExponentMultiplicationVisitor::VisitFraction(const Fraction* fraction) const {
    return CheckBaseMultiply(fraction);
}

MathElementPtr ExponentMultiplicationVisitor::VisitVariable(const Variable* variable) const {
    return CheckBaseMultiply(variable);
}

// Visit an Exponent
MathElementPtr ExponentMultiplicationVisitor::VisitExponent(const Exponent* exponent) const {
    if (Equal(operand_->base(), exponent->base())) {
        MathElementPtr added_exponents = Add(operand_->exponent(), exponent->exponent());
        return MathElementPtr(new Exponent(operand_->ClonedBase(), added_exponents->Clone()));
    } else {
        return MathElementPtr(new MultiplicationExpression(operand_->Clone(), exponent->Clone()));
    }
}

MathElementPtr ExponentMultiplicationVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    if (Equal(operand_->base(), expression)) {
        MathElementPtr exponent_plus_one = Add(operand_->exponent(), MathUtilities::One().get());
        return MathElementPtr(new Exponent(operand_->ClonedBase(), exponent_plus_one->Clone()));
    } else {
        // Let Expression handle it
        return Multiply(expression, operand_);
    }
}

MathElementPtr ExponentMultiplicationVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    return CheckBaseMultiply(expression);
}