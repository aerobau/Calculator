//
//  variable.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "variable.h"

Variable::Variable(char representation) : representation_(representation) {}

VisitorPtr Variable::CreateMultiplicationVisitor() const {
    return VisitorPtr(new VariableMultiplicationVisitor(this));
}

VisitorPtr Variable::CreateDivisionVisitor() const {
    return VisitorPtr(new VariableDivisionVisitor(this));
}

VisitorPtr Variable::CreateAdditionVisitor() const {
    return VisitorPtr(new VariableAdditionVisitor(this));
}

VisitorPtr Variable::CreateSubtractionVisitor() const {
    return VisitorPtr(new VariableSubtractionVisitor(this));
}

EqualityVisitorPtr Variable::CreateEqualityVisitor() const {
    return EqualityVisitorPtr(new VariableEqualityVisitor(this));
}

MathElementPtr Variable::Accept(const VisitorPtr visitor) const {
    return visitor->VisitVariable(this);
}

bool Variable::Accept(const EqualityVisitorPtr visitor) const {
    return visitor->VisitVariable(this);
}

double Variable::DoubleValue() const {
    return 0.0;
}

std::string Variable::ToString() const {
    std::stringstream stream;
    stream << representation_;
    return stream.str();
}

MathElementPtr Variable::Clone() const {
    return MathElementPtr(new Variable(representation_));
}

char Variable::representation() const {
    return representation_;
}