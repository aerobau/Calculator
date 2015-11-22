//
//  decimal_subtraction_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "decimal_subtraction_visitor.h"

// -- PRIVATE FUNCTIONS -- //

MathElementPtr DecimalSubtractionVisitor::
DecimalValue(const MathElement* first, const MathElement* second) const {
    double result_value = first->DoubleValue() - second->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// ++ PUBLIC FUNCTIONS ++ //

DecimalSubtractionVisitor::DecimalSubtractionVisitor(const Decimal* operand) : operand_(operand) {}


// VISITING FUNCTIONS //
// Visit various types and return the addition of the operand and the visited value

// Visit an Integer
MathElementPtr DecimalSubtractionVisitor::VisitInteger(const Integer* integer) const {
    return DecimalValue(operand_, integer);
}

// Visit a Decimal
MathElementPtr DecimalSubtractionVisitor::VisitDecimal(const Decimal* decimal) const {
    return DecimalValue(operand_, decimal);
}

// Visit a Fraction
MathElementPtr DecimalSubtractionVisitor::VisitFraction(const Fraction* fraction) const {
    return DecimalValue(operand_, fraction);
}

// Visit a Variable
MathElementPtr DecimalSubtractionVisitor::VisitVariable(const Variable* variable) const {
    return DecimalValue(operand_, variable);
}

// Visit an Exponent
MathElementPtr DecimalSubtractionVisitor::VisitExponent(const Exponent* exponent) const {
    return DecimalValue(operand_, exponent);
}

// Visit a MultiplicationExpression
MathElementPtr DecimalSubtractionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    return DecimalValue(operand_, expression);
}

// Visit an AdditionExpression
MathElementPtr DecimalSubtractionVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    return DecimalValue(operand_, expression);
}