//
//  decimal_multiplication_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "decimal_multiplication_visitor.h"

// Constructor: sets the operand
DecimalMultiplicationVisitor::DecimalMultiplicationVisitor(const Decimal* operand)
    : operand_(operand) {}


// VISITING FUNCTIONS //
// Visit various types and return the multiplication of the operand and the visited value

// Visit an integer
MathElementPtr DecimalMultiplicationVisitor::VisitInteger(const Integer* integer) const {
    // Return the resulting Decimal
    return DecimalResult(operand_, integer);
}

// Visit a decimal
MathElementPtr DecimalMultiplicationVisitor::VisitDecimal(const Decimal* decimal) const {
    // Return the resulting Decimal
    return DecimalResult(operand_, decimal);
}

// Visit a fraction
MathElementPtr DecimalMultiplicationVisitor::VisitFraction(const Fraction* fraction) const {
    // Return the resulting Decimal
    return DecimalResult(operand_, fraction);
}

// Visit a variable
MathElementPtr DecimalMultiplicationVisitor::VisitVariable(const Variable* variable) const {
    // Return the resulting Decimal
    return DecimalResult(operand_, variable);
}

// Visit a MultiplicationExpression
MathElementPtr DecimalMultiplicationVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    // Return the resulting Decimal
    return DecimalResult(operand_, expression);
}

// Calculate and return a unique ptr to a Decimal with the double values multiplied
MathElementPtr DecimalMultiplicationVisitor::
DecimalResult(const MathElement* first, const MathElement* second) const {
    // Getting the double value and constructing and returning a decimal
    double result_value = first->DoubleValue() * second->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}