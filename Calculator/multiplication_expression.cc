//
//  multiplication_expression.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "multiplication_expression.h"

MultiplicationExpression::MultiplicationExpression(std::vector<MathElementPtr> elements)
: elements_(std::move(elements)) {}

MultiplicationExpression::MultiplicationExpression(MathElementPtr first, MathElementPtr second)
: elements_(std::vector<MathElementPtr>()) {
    elements_.push_back(std::move(first));
    elements_.push_back(std::move(second));
}

VisitorPtr MultiplicationExpression::CreateMultiplicationVisitor() const {
    return VisitorPtr(new MultiplicationExpressionMultiplicationVisitor(this));
}

VisitorPtr MultiplicationExpression::CreateDivisionVisitor() const {
    return VisitorPtr(new MultiplicationExpressionDivisionVisitor(this));
}

VisitorPtr MultiplicationExpression::CreateAdditionVisitor() const {
    return VisitorPtr(new MultiplicationExpressionAdditionVisitor(this));
}

VisitorPtr MultiplicationExpression::CreateSubtractionVisitor() const {
    return VisitorPtr(new MultiplicationExpressionSubtractionVisitor(this));
}

EqualityVisitorPtr MultiplicationExpression::CreateEqualityVisitor() const {
    return EqualityVisitorPtr(new MultiplicationExpressionEqualityVisitor(this));
}


MathElementPtr MultiplicationExpression::Accept(const VisitorPtr visitor) const {
    return visitor->VisitMultiplicationExpression(this);
}

bool MultiplicationExpression::Accept(const EqualityVisitorPtr visitor) const {
    return visitor->VisitMultiplicationExpression(this);
}


double MultiplicationExpression::DoubleValue() const {
    double value = 1.0;
    for (int i = 0; i < elements_.size(); ++i) {
        value *= elements_[i]->DoubleValue();
    }
    return value;
}

std::string MultiplicationExpression::ToString() const {
    std::stringstream stream;
    stream << "(";
    for (int i = 0; i < elements_.size(); ++i) {
        stream << elements_[i]->ToString();
        if(i != elements_.size() - 1) {
            stream << " * ";
        }
    }
    stream << ")";
    return stream.str();
}


MathElementPtr MultiplicationExpression::Clone() const {
    std::vector<MathElementPtr> cloned_elements;
    for (int i = 0; i < elements_.size(); ++i) {
        cloned_elements.push_back(elements_[i]->Clone());
    }
    return MathElementPtr(new MultiplicationExpression(std::move(cloned_elements)));
}

const std::vector<MathElementPtr>* MultiplicationExpression::elements() const {
    return &elements_;
}

std::vector<MathElementPtr> MultiplicationExpression::ClonedElements() const {
    std::vector<MathElementPtr> cloned_elements;
    for (int i = 0; i < elements_.size(); ++i) {
        cloned_elements.push_back(elements_[i]->Clone());
    }
    return cloned_elements;
}

std::size_t MultiplicationExpression::NumberOfElements() const {
    return elements_.size();
}

