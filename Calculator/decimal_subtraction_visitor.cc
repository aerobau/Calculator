//
//  decimal_subtraction_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "decimal_subtraction_visitor.h"

DecimalSubtractionVisitor::DecimalSubtractionVisitor(const Decimal* operand) : operand_(operand) {}


// VISITING FUNCTIONS //
// Visit various types and return the addition of the operand and the visited value

// Visit an Integer
MathElementPtr DecimalSubtractionVisitor::VisitInteger(const Integer* integer) const {
    // Finding the double difference and constructing and returning a Decimal
    double result_value = operand_->DoubleValue() - integer->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Decimal
MathElementPtr DecimalSubtractionVisitor::VisitDecimal(const Decimal* decimal) const {
    // Finding the double difference and constructing and returning a Decimal
    double result_value = operand_->DoubleValue() - decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr DecimalSubtractionVisitor::VisitFraction(const Fraction* fraction) const {
    // Finding the double difference and constructing and returning a Decimal
    double result_value = operand_->DoubleValue() - fraction->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Variable
MathElementPtr DecimalSubtractionVisitor::VisitVariable(const Variable* variable) const {
    return MathElementPtr(nullptr);
}