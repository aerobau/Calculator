//
//  variable.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "variable.h"

Variable::Variable(char representation) : representation_(representation) {}

Visitor* Variable::CreateMultiplicationVisitor() const {
    return new VariableMultiplicationVisitor(this);
}

Visitor* Variable::CreateDivisionVisitor() const {
    return new VariableDivisionVisitor(this);
}

Visitor* Variable::CreateAdditionVisitor() const {
    return new VariableAdditionVisitor(this);
}

Visitor* Variable::CreateSubtractionVisitor() const {
    return new VariableSubtractionVisitor(this);
}

EqualityVisitor* Variable::CreateEqualityVisitor() const {
    return new VariableEqualityVisitor(this);
}

MathElementPtr Variable::Accept(const Visitor* visitor) const {
    return visitor->VisitVariable(this);
}

bool Variable::Accept(const EqualityVisitor* visitor) const {
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