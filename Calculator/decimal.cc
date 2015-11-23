//
//  decimal.cpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "decimal.h"

Decimal::Decimal(double value): value_(value) {}

VisitorPtr Decimal::CreateMultiplicationVisitor() const {
    return VisitorPtr(new DecimalMultiplicationVisitor(this));
}

VisitorPtr Decimal::CreateDivisionVisitor() const {
    return VisitorPtr(new DecimalDivisionVisitor(this));
}

VisitorPtr Decimal::CreateAdditionVisitor() const {
    return VisitorPtr(new DecimalAdditionVisitor(this));
}

VisitorPtr Decimal::CreateSubtractionVisitor() const {
    return VisitorPtr(new DecimalSubtractionVisitor(this));
}

EqualityVisitorPtr Decimal::CreateEqualityVisitor() const {
    return EqualityVisitorPtr(new DecimalEqualityVisitor(this));
}

MathElementPtr Decimal::Accept(const VisitorPtr visitor) const {
    return visitor->VisitDecimal(this);
}

bool Decimal::Accept(const EqualityVisitorPtr visitor) const {
    return visitor->VisitDecimal(this);
}

MathElementPtr Decimal::
Exchange(const MathElement* old_element, const MathElement* new_element) const {
    if (old_element->Accept(CreateEqualityVisitor())) {
        return new_element->Clone();
    } else {
        return Clone();
    }
}

double Decimal::DoubleValue() const {
    return value_;
}

std::string Decimal::ToString() const {
    std::stringstream stream;
    stream << value_;
    return stream.str();
}

MathElementPtr Decimal::Clone() const {
    return MathElementPtr(new Decimal(value_));
}