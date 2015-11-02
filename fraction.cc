//
//  fraction.cpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "fraction.h"

Fraction::Fraction(MathElementPtr numerator, MathElementPtr denominator)
: numerator_(std::move(numerator)), denominator_(std::move(denominator)) {}

Visitor* Fraction::CreateMultiplicationVisitor() const {
    return new FractionMultiplicationVisitor(this);
}

Visitor* Fraction::CreateDivisionVisitor() const {
    return new FractionDivisionVisitor(this);
}

Visitor* Fraction::CreateAdditionVisitor() const {
    return new FractionAdditionVisitor(this);
}

Visitor* Fraction::CreateSubtractionVisitor() const {
    return new FractionSubtractionVisitor(this);
}

EqualityVisitor* Fraction::CreateEqualityVisitor() const {
    return new FractionEqualityVisitor(this);
}



MathElementPtr Fraction::Accept(const Visitor* visitor) const {
    return visitor->VisitFraction(this);
}

bool Fraction::Accept(const EqualityVisitor* visitor) const {
    return visitor->VisitFraction(this);
}



double Fraction::DoubleValue() const {
    return numerator_->DoubleValue() / denominator_ -> DoubleValue();
}

std::string Fraction::ToString() const {
    std::stringstream stream;
    stream << numerator_->ToString() << " / " << denominator_->ToString();
    return stream.str();
}



MathElementPtr Fraction::Clone() const {
    MathElementPtr numerator = MathElementPtr(numerator_->Clone());
    MathElementPtr denominator = MathElementPtr(denominator_->Clone());
    return MathElementPtr(new Fraction(std::move(numerator), std::move(denominator)));
}



const MathElement* Fraction::numerator() const {
    return numerator_.get();
}

const MathElement* Fraction::denominator() const {
    return denominator_.get();
}

MathElementPtr Fraction::ClonedNumerator() const {
    return MathElementPtr(numerator_->Clone());
}

MathElementPtr Fraction::ClonedDenominator() const {
    return MathElementPtr(denominator_->Clone());
}


MathElementPtr Fraction::invert() const {
    return MathElementPtr(new Fraction(ClonedDenominator(), ClonedNumerator()));
}