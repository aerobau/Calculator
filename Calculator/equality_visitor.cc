//
//  equality_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "equality_visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"

IntegerEqualityVisitor::IntegerEqualityVisitor(const Integer* operand) : operand_(operand) {}

bool IntegerEqualityVisitor::VisitInteger(const Integer* integer) const {
    return operand_->value() == integer->value();
}

DecimalEqualityVisitor::DecimalEqualityVisitor(const Decimal* operand) : operand_(operand) {}

bool DecimalEqualityVisitor::VisitDecimal(const Decimal* decimal) const {
    return operand_->DoubleValue() == decimal->DoubleValue();
}

FractionEqualityVisitor::FractionEqualityVisitor(const Fraction* operand) : operand_(operand) {}

bool FractionEqualityVisitor::VisitFraction(const Fraction* fraction) const {
    EqualityVisitor* numerator_visit = operand_->numerator()->CreateEqualityVisitor();
    EqualityVisitor* denominator_visit = operand_->denominator()->CreateEqualityVisitor();
    return fraction->numerator()->Accept(numerator_visit) &&
           fraction->denominator()->Accept(denominator_visit);
}

VariableEqualityVisitor::VariableEqualityVisitor(const Variable* operand) : operand_(operand) {}

bool VariableEqualityVisitor::VisitVariable(const Variable* variable) const {
    return operand_->representation() == variable->representation();
}

MultiplicationExpressionEqualityVisitor::MultiplicationExpressionEqualityVisitor(const MultiplicationExpression* operand) : operand_(operand) {}

bool MultiplicationExpressionEqualityVisitor::VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    return false;
}