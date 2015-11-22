//
//  exponent_addition_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/21/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "exponent_addition_visitor.h"

ExponentAdditionVisitor::ExponentAdditionVisitor(const Exponent* operand) : operand_(operand) {}

MathElementPtr ExponentAdditionVisitor::VisitInteger(const Integer* integer) const {
    return MathElementPtr(new AdditionExpression(operand_->Clone(), integer->Clone()));
}

MathElementPtr ExponentAdditionVisitor::VisitDecimal(const Decimal* decimal) const {
    double result_value = operand_->DoubleValue() + decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

MathElementPtr ExponentAdditionVisitor::VisitFraction(const Fraction* fraction) const {
    return MathElementPtr(new AdditionExpression(operand_->Clone(), fraction->Clone()));
}

MathElementPtr ExponentAdditionVisitor::VisitVariable(const Variable* variable) const {
    return MathElementPtr(new AdditionExpression(operand_->Clone(), variable->Clone()));
}

MathElementPtr ExponentAdditionVisitor::VisitExponent(const Exponent* exponent) const {
    if (Equal(operand_, exponent)) {
        return MathElementPtr(new MultiplicationExpression(MathUtilities::Two(),
                                                           operand_->Clone()));
    } else {
        return MathElementPtr(new AdditionExpression(operand_->Clone(), exponent->Clone()));
    }
}

MathElementPtr ExponentAdditionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    return MathElementPtr(new AdditionExpression(operand_->Clone(), expression->Clone()));
}

MathElementPtr ExponentAdditionVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    return Add(expression, operand_);
}