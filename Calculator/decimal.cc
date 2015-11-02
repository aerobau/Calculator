//
//  decimal.cpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "decimal.h"

Decimal::Decimal(double value): value_(value) {}

Visitor* Decimal::CreateMultiplicationVisitor() const {
    return new DecimalMultiplicationVisitor(this);
}

Visitor* Decimal::CreateDivisionVisitor() const {
    return new DecimalDivisionVisitor(this);
}

Visitor* Decimal::CreateAdditionVisitor() const {
    return new DecimalAdditionVisitor(this);
}

Visitor* Decimal::CreateSubtractionVisitor() const {
    return new DecimalSubtractionVisitor(this);
}

EqualityVisitor* Decimal::CreateEqualityVisitor() const {
    return new DecimalEqualityVisitor(this);
}

MathElementPtr Decimal::Accept(const Visitor* visitor) const {
    return visitor->VisitDecimal(this);
}

bool Decimal::Accept(const EqualityVisitor* visitor) const {
    return visitor->VisitDecimal(this);
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