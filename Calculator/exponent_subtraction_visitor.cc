//
//  exponent_subtraction_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/21/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "exponent_subtraction_visitor.h"

// -- PRIVATE FUNCTIONS -- //

MathElementPtr ExponentSubtractionVisitor::AddNegation(const MathElement* element) const {
    MathElementPtr negation = Multiply(MathUtilities::NegativeOne().get(), element);
    return Add(operand_, negation.get());
}

// ++ PUBLIC FUNCTIONS ++ //

ExponentSubtractionVisitor::ExponentSubtractionVisitor(const Exponent* operand)
    : operand_(operand) {}

MathElementPtr ExponentSubtractionVisitor::VisitInteger(const Integer* integer) const {
    return AddNegation(integer);
}

MathElementPtr ExponentSubtractionVisitor::VisitDecimal(const Decimal* decimal) const {
    double result_value = operand_->DoubleValue() - decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

MathElementPtr ExponentSubtractionVisitor::VisitFraction(const Fraction* fraction) const {
    return AddNegation(fraction);
}

MathElementPtr ExponentSubtractionVisitor::VisitVariable(const Variable* variable) const {
    return AddNegation(variable);
}

MathElementPtr ExponentSubtractionVisitor::VisitExponent(const Exponent* exponent) const {
    if (Equal(operand_, exponent)) {
        return MathUtilities::Zero();
    } else {
        return AddNegation(exponent);
    }
}

MathElementPtr ExponentSubtractionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    return AddNegation(expression);
}

MathElementPtr ExponentSubtractionVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    return AddNegation(expression);
}