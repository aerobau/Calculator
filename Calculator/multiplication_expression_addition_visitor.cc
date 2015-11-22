//
//  multiplication_expression_addition_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "multiplication_expression_addition_visitor.h"

// ++ PUBLIC FUNCTIONS ++ //

// Constructor
MultiplicationExpressionAdditionVisitor::
MultiplicationExpressionAdditionVisitor(const MultiplicationExpression* operand)
    : operand_(operand) {}

// Visit an Integer
MathElementPtr MultiplicationExpressionAdditionVisitor::VisitInteger(const Integer* integer) const {
    return MathElementPtr(new AdditionExpression(operand_->Clone(), integer->Clone()));
}

// Visit a Decimal
MathElementPtr MultiplicationExpressionAdditionVisitor::VisitDecimal(const Decimal* decimal) const {
    double result_value = operand_->DoubleValue() + decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr MultiplicationExpressionAdditionVisitor::
VisitFraction(const Fraction* fraction) const {
    return MathElementPtr(new AdditionExpression(operand_->Clone(), fraction->Clone()));
}

// Visit a Variable
MathElementPtr MultiplicationExpressionAdditionVisitor::
VisitVariable(const Variable* variable) const {
    return MathElementPtr(new AdditionExpression(operand_->Clone(), variable->Clone()));
}

// Visit an Exponent
MathElementPtr MultiplicationExpressionAdditionVisitor::
VisitExponent(const Exponent* exponent) const {
    return MathElementPtr(new AdditionExpression(operand_->Clone(), exponent->Clone()));
}

// Visit a m=MultiplicationExpression
MathElementPtr MultiplicationExpressionAdditionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    if (Equal(operand_, expression)) {
        return MathElementPtr(new MultiplicationExpression(MathUtilities::Two(),
                                                           operand_->Clone()));
    } else {
        return MathElementPtr(new AdditionExpression(operand_->Clone(), expression->Clone()));
    }
}

// Visit an AdditionExpression
MathElementPtr MultiplicationExpressionAdditionVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    // Allow expression to handle
    return Add(expression, operand_);
}
