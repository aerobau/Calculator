//
//  decimal_addition_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "decimal_addition_visitor.h"

// -- PRIVATE FUNCTIONS -- //

MathElementPtr DecimalAdditionVisitor::
DecimalValue(const MathElement* first, const MathElement* second) const {
    double result_value = first->DoubleValue() + second->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// ++ PUBLIC FUNCTIONS ++ //

// Constructor
DecimalAdditionVisitor::DecimalAdditionVisitor(const Decimal* operand) : operand_(operand) {}

// VISITING FUNCTIONS //
// Visit various types and return the addition of the operand and the visited value

// Visit an Integer
MathElementPtr DecimalAdditionVisitor::VisitInteger(const Integer* integer) const {
    return DecimalValue(operand_, integer);
}

// Visit a Decimal
MathElementPtr DecimalAdditionVisitor::VisitDecimal(const Decimal* decimal) const {
    return DecimalValue(operand_, decimal);
}

// Visit a Fraction
MathElementPtr DecimalAdditionVisitor::VisitFraction(const Fraction* fraction) const {
    return DecimalValue(operand_, fraction);
}

// Visit a Variable
MathElementPtr DecimalAdditionVisitor::VisitVariable(const Variable* variable) const {
    return DecimalValue(operand_, variable);
}

// Visit a MultiplicationExpression
MathElementPtr DecimalAdditionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    return DecimalValue(operand_, expression);
}

MathElementPtr DecimalAdditionVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    return DecimalValue(operand_, expression);
}