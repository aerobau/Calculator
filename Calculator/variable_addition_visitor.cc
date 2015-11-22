//
//  variable_addition_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "variable_addition_visitor.h"

// ++ PUBLIC FUNCTIONS ++ //

// Constructor
VariableAdditionVisitor::VariableAdditionVisitor(const Variable* operand) : operand_(operand) {}

// VISITING FUNCTIONS //

// Visit an Integer
MathElementPtr VariableAdditionVisitor::VisitInteger(const Integer* integer) const {
    return MathElementPtr(new AdditionExpression(operand_->Clone(), integer->Clone()));
}

// Visit a Decimal
MathElementPtr VariableAdditionVisitor::VisitDecimal(const Decimal* decimal) const {
    double result_value = operand_->DoubleValue() + decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr VariableAdditionVisitor::VisitFraction(const Fraction* fraction) const {
    return MathElementPtr(new AdditionExpression(operand_->Clone(), fraction->Clone()));
}

// Visit a Variable
MathElementPtr VariableAdditionVisitor::VisitVariable(const Variable* variable) const {
    if (Equal(operand_, variable)) {
        // If the variables are equal, return a multiplication to represent 2 times the variable
        return MathElementPtr(new MultiplicationExpression(MathUtilities::Two(),
                                                           variable->Clone()));
    } else {
        return MathElementPtr(new AdditionExpression(operand_->Clone(), variable->Clone()));
    }
}

// Visit an Exponent
MathElementPtr VariableAdditionVisitor::VisitExponent(const Exponent* exponent) const {
    return MathElementPtr(new AdditionExpression(operand_->Clone(), exponent->Clone()));
}

// Visit a MultiplicationExpression
MathElementPtr VariableAdditionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    return MathElementPtr(new AdditionExpression(operand_->Clone(), expression->Clone()));
}

// Visit an AdditionExpression
MathElementPtr VariableAdditionVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    // Allow expression to handle
    return Multiply(expression, operand_);
}