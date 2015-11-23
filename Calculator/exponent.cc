//
//  exponent.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/21/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "exponent.h"
#include "exponent_multiplication_visitor.h"
#include "exponent_division_visitor.h"
#include "exponent_addition_visitor.h"
#include "exponent_subtraction_visitor.h"
#include <math.h>

Exponent::Exponent(MathElementPtr base, MathElementPtr exponent)
: base_(std::move(base)), exponent_(std::move(exponent)) {}

// TODO: Rewrite visitors
VisitorPtr Exponent::CreateMultiplicationVisitor() const {
    return VisitorPtr(new ExponentMultiplicationVisitor(this));
}

VisitorPtr Exponent::CreateDivisionVisitor() const {
    return VisitorPtr(new ExponentDivisionVisitor(this));
}

VisitorPtr Exponent::CreateAdditionVisitor() const {
    return VisitorPtr(new ExponentAdditionVisitor(this));
}

VisitorPtr Exponent::CreateSubtractionVisitor() const {
    return VisitorPtr(new ExponentSubtractionVisitor(this));
}

EqualityVisitorPtr Exponent::CreateEqualityVisitor() const {
    return EqualityVisitorPtr(new ExponentEqualityVisitor(this));
}

MathElementPtr Exponent::Accept(const VisitorPtr visitor) const {
    return MathElementPtr(nullptr);
}

bool Exponent::Accept(const EqualityVisitorPtr visitor) const {
    return false;
}

MathElementPtr Exponent::
Exchange(const MathElement* old_element, const MathElement* new_element) const {
    if (old_element->Accept(CreateEqualityVisitor())) {
        return new_element->Clone();
    } else {
        return MathElementPtr(new Exponent(base_->Exchange(old_element, new_element),
                                           exponent_->Exchange(old_element, new_element)));
    }
}

double Exponent::DoubleValue() const {
    return pow(base_->DoubleValue(), exponent_->DoubleValue());
}

std::string Exponent::ToString() const {
    std::stringstream stream;
    stream << "(" << base_->ToString() << ")^(" << exponent_->ToString() << ")";
    return stream.str();
}

MathElementPtr Exponent::Clone() const {
    return MathElementPtr(new Exponent(ClonedBase(), ClonedExponent()));
}

const MathElement* Exponent::base() const {
    return base_.get();
}

const MathElement* Exponent::exponent() const {
    return exponent_.get();
}

MathElementPtr Exponent::ClonedBase() const {
    return base_->Clone();
}

MathElementPtr Exponent::ClonedExponent() const {
    return exponent_->Clone();
}



