//
//  multiplication_expression_subtraction_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "multiplication_expression_subtraction_visitor.h"

// -- PRIVATE FUNCTIONS -- //

MathElementPtr MultiplicationExpressionSubtractionVisitor::
AddNegation(const MathElement* element) const {
    MathElementPtr negation = Multiply(MathUtilities::NegativeOne().get(), element);
    return Add(operand_, negation.get());
}

// ++ PUBLIC FUNCTIONS ++ //

// Constructor
MultiplicationExpressionSubtractionVisitor::
MultiplicationExpressionSubtractionVisitor(const MultiplicationExpression* operand)
    : operand_(operand) {}

// VISITOR FUNCTIONS //

// Visit and Integer
MathElementPtr MultiplicationExpressionSubtractionVisitor::
VisitInteger(const Integer* integer) const {
    return AddNegation(integer);
}

// Visit a Decimal
MathElementPtr MultiplicationExpressionSubtractionVisitor::
VisitDecimal(const Decimal* decimal) const {
    double result_value = operand_->DoubleValue() - decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr MultiplicationExpressionSubtractionVisitor::
VisitFraction(const Fraction* fraction) const {
    return AddNegation(fraction);
}

// Visit a Variable
MathElementPtr MultiplicationExpressionSubtractionVisitor::
VisitVariable(const Variable* variable) const {
    return AddNegation(variable);
}

// Visit an Exponent
MathElementPtr MultiplicationExpressionSubtractionVisitor::
VisitExponent(const Exponent* exponent) const {
    return AddNegation(exponent);
}

// Visit a MultiplicationExpression
MathElementPtr MultiplicationExpressionSubtractionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    if (Equal(operand_, expression)) {
        return MathUtilities::Zero();
    } else {
        return AddNegation(expression);
    }
}

// Visit an AdditionExpression
MathElementPtr MultiplicationExpressionSubtractionVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    return AddNegation(expression);
}