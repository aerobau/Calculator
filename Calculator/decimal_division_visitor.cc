//
//  decimal_division_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "decimal_division_visitor.h"

// Constructor: sets the operand
DecimalDivisionVisitor::DecimalDivisionVisitor(const Decimal* operand) : operand_(operand) {}

// VISITING FUNCTIONS //
// Visit various types and return the division of the operand and the visited value

// Visit an integer
MathElementPtr DecimalDivisionVisitor::VisitInteger(const Integer* integer) const {
    // Dividing the double values, constructing and returning a Decimal
    return DecimalValue(operand_, integer);
}

// Visit a Decimal
MathElementPtr DecimalDivisionVisitor::VisitDecimal(const Decimal* decimal) const {
    // Dividing the double values, constructing and returning a Decimal
    return DecimalValue(operand_, decimal);
}

// Visit a Fraction
MathElementPtr DecimalDivisionVisitor::VisitFraction(const Fraction* fraction) const {
    // Dividing the double values, constructing and returning a Decimal
    return DecimalValue(operand_, fraction);
}

// Visit a Variable
MathElementPtr DecimalDivisionVisitor::VisitVariable(const Variable* variable) const {
    // Dividing the double values, constructing and returning a Decimal
    return DecimalValue(operand_, variable);
}

MathElementPtr DecimalDivisionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    // Dividing the double values, constructing and returning a Decimal
    return DecimalValue(operand_, expression);
}

MathElementPtr DecimalDivisionVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    // Dividing the double values, constructing and returning a Decimal
    return DecimalValue(operand_, expression);
}

MathElementPtr DecimalDivisionVisitor::
DecimalValue(const MathElement* first, const MathElement* second) const {
    // Dividing the double values, constructing and returning a Decimal
    double result_value = first->DoubleValue() / second->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}