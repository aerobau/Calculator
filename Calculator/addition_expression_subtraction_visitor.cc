//
//  addition_expression_subtraction_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/4/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "addition_expression_subtraction_visitor.h"

// -- PRIVATE FUNCTIONS -- //

MathElementPtr AdditionExpressionSubtractionVisitor::AddNegation(const MathElement* element) const {
    MathElementPtr negation = Multiply(MathUtilities::NegativeOne().get(), element);
    return Add(operand_, negation.get());
}

// ++ PUBLIC FUNCTIONS ++ //

AdditionExpressionSubtractionVisitor::
AdditionExpressionSubtractionVisitor(const AdditionExpression* operand) : operand_(operand) {}

MathElementPtr AdditionExpressionSubtractionVisitor::VisitInteger(const Integer* integer) const {
    return AddNegation(integer);
}

MathElementPtr AdditionExpressionSubtractionVisitor::VisitDecimal(const Decimal* decimal) const {
    double result_value = operand_->DoubleValue() + decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

MathElementPtr AdditionExpressionSubtractionVisitor::VisitFraction(const Fraction* fraction) const {
    return AddNegation(fraction);
}

MathElementPtr AdditionExpressionSubtractionVisitor::VisitVariable(const Variable* variable) const {
    return AddNegation(variable);
}

MathElementPtr AdditionExpressionSubtractionVisitor::VisitExponent(const Exponent* exponent) const {
    return AddNegation(exponent);
}

MathElementPtr AdditionExpressionSubtractionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    return AddNegation(expression);
}

MathElementPtr AdditionExpressionSubtractionVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    if (Equal(operand_, expression)) {
        return MathUtilities::Zero();
    } else {
        return AddNegation(expression);
    }
}