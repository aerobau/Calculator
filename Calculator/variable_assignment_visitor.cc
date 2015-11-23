//
//  VariableAssignmentVisitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/23/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "variable_assignment_visitor.h"
#include "variable.h"

VariableAssignmentVisitor::
VariableAssignmentVisitor(const Variable* variable, const MathElement* replacement)
    : variable_(variable), replacement_(replacement) {}

bool VariableAssignmentVisitor::NeedsReplacement(const Variable* visited) const {
    return variable_->representation() == visited->representation();
}

const Variable* VariableAssignmentVisitor::variable() const {
    return variable_;
}

const MathElement* VariableAssignmentVisitor::replacement() const {
    return replacement_;
}

MathElementPtr VariableAssignmentVisitor::ClonedVariable() const {
    return variable_->Clone();
}

MathElementPtr VariableAssignmentVisitor::ClonedReplacement() const {
    return replacement_->Clone();
}
