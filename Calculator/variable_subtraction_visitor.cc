//
//  variable_subtraction_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "variable_subtraction_visitor.h"

VariableSubtractionVisitor::VariableSubtractionVisitor(const Variable* operand) : operand_(operand) {}

MathElementPtr VariableSubtractionVisitor::VisitInteger(const Integer* integer) const {
    return MathElementPtr(nullptr);
}

MathElementPtr VariableSubtractionVisitor::VisitDecimal(const Decimal* decimal) const {
    return MathElementPtr(nullptr);
}

MathElementPtr VariableSubtractionVisitor::VisitFraction(const Fraction* fraction) const {
    return MathElementPtr(nullptr);
}

MathElementPtr VariableSubtractionVisitor::VisitVariable(const Variable* variable) const {
    return MathElementPtr(nullptr);
}