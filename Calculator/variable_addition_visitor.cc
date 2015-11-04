//
//  variable_addition_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "variable_addition_visitor.h"

VariableAdditionVisitor::VariableAdditionVisitor(const Variable* operand) : operand_(operand) {}

MathElementPtr VariableAdditionVisitor::VisitInteger(const Integer* integer) const {
    return MathElementPtr(nullptr);
}

MathElementPtr VariableAdditionVisitor::VisitDecimal(const Decimal* decimal) const {
    return MathElementPtr(nullptr);
}

MathElementPtr VariableAdditionVisitor::VisitFraction(const Fraction* fraction) const {
    return MathElementPtr(nullptr);
}

MathElementPtr VariableAdditionVisitor::VisitVariable(const Variable* variable) const {
    return MathElementPtr(nullptr);
}