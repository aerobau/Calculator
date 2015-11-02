//
//  integer.cpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "integer.h"

Integer::Integer(int value) : value_(value) {}


// MATH ELEMENT OVERRIDES //

// VISITOR CREATION METHODS // Create different visitors based on function

Visitor* Integer::CreateMultiplicationVisitor() const {
    return new IntegerMultiplicationVisitor(this);
}

Visitor* Integer::CreateDivisionVisitor() const {
    return new IntegerDivisionVisitor(this);
}

Visitor* Integer::CreateAdditionVisitor() const {
    return new IntegerAdditionVisitor(this);
}

Visitor* Integer::CreateSubtractionVisitor() const {
    return new IntegerSubtractionVisitor(this);
}

EqualityVisitor* Integer::CreateEqualityVisitor() const {
    return new IntegerEqualityVisitor(this);
}

// VISITOR ACCEPTION METHODS // Accept and double dispatch to visitors

MathElementPtr Integer::Accept(const Visitor* visitor) const {
    return visitor->VisitInteger(this);
}

bool Integer::Accept(const EqualityVisitor* visitor) const {
    return visitor->VisitInteger(this);
}

// REPRESENTATION CREATION METHODS // Return the double and std::string representations

double Integer::DoubleValue() const {
    return (double) value_;
}

std::string Integer::ToString() const {
    std::stringstream stream;
    stream << value_;
    return stream.str();
}

MathElementPtr Integer::Clone() const {
    return MathElementPtr(new Integer(value_));
}

int Integer::value() const {
    return value_;
}







