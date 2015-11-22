//
//  variable_subtraction_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "variable_subtraction_visitor.h"

// -- PRIVATE FUNCTIONS -- //

MathElementPtr VariableSubtractionVisitor::AddNegation(const MathElement* element) const {
    MathElementPtr negation = Multiply(MathUtilities::NegativeOne().get(), element);
    return Add(operand_, negation.get());
}

// ++ PUBLIC FUNCTIONS ++ //

VariableSubtractionVisitor::VariableSubtractionVisitor(const Variable* operand)
    : operand_(operand) {}

MathElementPtr VariableSubtractionVisitor::VisitInteger(const Integer* integer) const {
    return AddNegation(integer);
}

MathElementPtr VariableSubtractionVisitor::VisitDecimal(const Decimal* decimal) const {
    return AddNegation(decimal);
}

MathElementPtr VariableSubtractionVisitor::VisitFraction(const Fraction* fraction) const {
    return AddNegation(fraction);
}

MathElementPtr VariableSubtractionVisitor::VisitVariable(const Variable* variable) const {
    return AddNegation(variable);
}

MathElementPtr VariableSubtractionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    return AddNegation(expression);
}

MathElementPtr VariableSubtractionVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    return AddNegation(expression);
}