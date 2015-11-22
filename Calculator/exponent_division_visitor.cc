//
//  exponent_division_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/21/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "exponent_division_visitor.h"

// -- PRIVATE FUNCTIONS -- //

MathElementPtr ExponentDivisionVisitor::CheckBaseDivide(const MathElement* element) const {
    if (Equal(operand_->base(), element)) {
        MathElementPtr exponent_minus_one = Subtract(operand_->exponent(),
                                                     MathUtilities::One().get());
        return MathElementPtr(new Exponent(operand_->ClonedBase(), exponent_minus_one->Clone()));
    } else {
        return MathElementPtr(new Fraction(operand_->Clone(), element->Clone()));
    }
}

// ++ PUBLIC FUNCTIONS ++ //

ExponentDivisionVisitor::ExponentDivisionVisitor(const Exponent* operand) : operand_(operand) {}

MathElementPtr ExponentDivisionVisitor::VisitInteger(const Integer* integer) const {
    return CheckBaseDivide(integer);
}

MathElementPtr ExponentDivisionVisitor::VisitDecimal(const Decimal* decimal) const {
    double result_value = operand_->DoubleValue() / decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

MathElementPtr ExponentDivisionVisitor::VisitFraction(const Fraction* fraction) const {
    return CheckBaseDivide(fraction);
}

MathElementPtr ExponentDivisionVisitor::VisitVariable(const Variable* variable) const {
    return CheckBaseDivide(variable);
}

MathElementPtr ExponentDivisionVisitor::VisitExponent(const Exponent* exponent) const {
    if (Equal(operand_->base(), exponent->base())) {
        MathElementPtr subtracted_exponents = Subtract(operand_->exponent(), exponent->exponent());
        return MathElementPtr(new Exponent(operand_->ClonedBase(), subtracted_exponents->Clone()));
    } else {
        return MathElementPtr(new Fraction(operand_->Clone(), exponent->Clone()));
    }
}

MathElementPtr ExponentDivisionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    return CheckBaseDivide(expression);
}

MathElementPtr ExponentDivisionVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    return CheckBaseDivide(expression);
}