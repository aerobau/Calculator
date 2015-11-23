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

VisitorPtr Fraction::CreateMultiplicationVisitor() const {
    return VisitorPtr(new FractionMultiplicationVisitor(this));
}

VisitorPtr Fraction::CreateDivisionVisitor() const {
    return VisitorPtr(new FractionDivisionVisitor(this));
}

VisitorPtr Fraction::CreateAdditionVisitor() const {
    return VisitorPtr(new FractionAdditionVisitor(this));
}

VisitorPtr Fraction::CreateSubtractionVisitor() const {
    return VisitorPtr(new FractionSubtractionVisitor(this));
}

EqualityVisitorPtr Fraction::CreateEqualityVisitor() const {
    return EqualityVisitorPtr(new FractionEqualityVisitor(this));
}



MathElementPtr Fraction::Accept(const VisitorPtr visitor) const {
    return visitor->VisitFraction(this);
}

bool Fraction::Accept(const EqualityVisitorPtr visitor) const {
    return visitor->VisitFraction(this);
}



MathElementPtr Fraction::
Exchange(const MathElement* old_element, const MathElement* new_element) const {
    if (old_element->Accept(CreateEqualityVisitor())) {
        return new_element->Clone();
    } else {
        return MathElementPtr(new Fraction(numerator_->Exchange(old_element, new_element),
                                           denominator_->Exchange(old_element, new_element)));
    }
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


MathElementPtr Fraction::Invert() const {
    return MathElementPtr(new Fraction(ClonedDenominator(), ClonedNumerator()));
}