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

VisitorPtr Integer::CreateMultiplicationVisitor() const {
    return VisitorPtr(new IntegerMultiplicationVisitor(this));
}

VisitorPtr Integer::CreateDivisionVisitor() const {
    return VisitorPtr(new IntegerDivisionVisitor(this));
}

VisitorPtr Integer::CreateAdditionVisitor() const {
    return VisitorPtr(new IntegerAdditionVisitor(this));
}

VisitorPtr Integer::CreateSubtractionVisitor() const {
    return VisitorPtr(new IntegerSubtractionVisitor(this));
}

EqualityVisitorPtr Integer::CreateEqualityVisitor() const {
    return EqualityVisitorPtr(new IntegerEqualityVisitor(this));
}

// VISITOR ACCEPTION METHODS // Accept and double dispatch to visitors

MathElementPtr Integer::Accept(const VisitorPtr visitor) const {
    return visitor->VisitInteger(this);
}

bool Integer::Accept(const EqualityVisitorPtr visitor) const {
    return visitor->VisitInteger(this);
}

MathElementPtr Integer::
Exchange(const MathElement* old_element, const MathElement* new_element) const {
    if (old_element->Accept(CreateEqualityVisitor())) {
        return new_element->Clone();
    } else {
      return Clone();
    }
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







