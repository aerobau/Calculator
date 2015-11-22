//
//  addition_expression.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/4/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "addition_expression.h"
#include "addition_expression_multiplication_visitor.h"
#include "addition_expression_division_visitor.h"
#include "addition_expression_addition_visitor.h"
#include "addition_expression_subtraction_visitor.h"

// Constructor intitializes the elements
AdditionExpression::AdditionExpression(std::vector<MathElementPtr> elements)
    : elements_(std::move(elements)) {}

AdditionExpression::AdditionExpression(MathElementPtr first, MathElementPtr second)
: elements_(std::vector<MathElementPtr>()) {
    elements_.push_back(std::move(first));
    elements_.push_back(std::move(second));
}

// MathElement overrides //

// Visitor factory methods

VisitorPtr AdditionExpression::CreateMultiplicationVisitor() const {
    return VisitorPtr(new AdditionExpressionMultiplicationVisitor(this));
}

VisitorPtr AdditionExpression::CreateDivisionVisitor() const {
    return VisitorPtr(new AdditionExpressionDivisionVisitor(this));
}

VisitorPtr AdditionExpression::CreateAdditionVisitor() const {
    return VisitorPtr(new AdditionExpressionAdditionVisitor(this));
}

VisitorPtr AdditionExpression::CreateSubtractionVisitor() const {
    return VisitorPtr(new AdditionExpressionSubtractionVisitor(this));
}

EqualityVisitorPtr AdditionExpression::CreateEqualityVisitor() const {
    return EqualityVisitorPtr(new AdditionExpressionEqualityVisitor(this));
}

// Visitor acception methods

MathElementPtr AdditionExpression::Accept(const VisitorPtr visitor) const {
    return visitor->VisitAdditionExpression(this);
}

bool AdditionExpression::Accept(const EqualityVisitorPtr visitor) const {
    return visitor->VisitAdditionExpression(this);
}

// Common value methods

double AdditionExpression::DoubleValue() const {
    double value = 0;
    for (int i = 0; i < elements_.size(); ++i) {
        value += elements_[i]->DoubleValue();
    }
    return value;
}

std::string AdditionExpression::ToString() const {
    std::stringstream stream;
    for (int i = 0; i < elements_.size(); ++i) {
        stream << elements_[i]->ToString();
        if (i != elements_.size() - 1) {
            stream << " + ";
        }
    }
    return stream.str();
}

// Cloning function

MathElementPtr AdditionExpression::Clone() const {
    return MathElementPtr(new AdditionExpression(ClonedElements()));
}

// Class specific functions //

const std::vector<MathElementPtr>* AdditionExpression::elements() const {
    return &elements_;
}

std::vector<MathElementPtr> AdditionExpression::ClonedElements() const {
    std::vector<MathElementPtr> cloned_elements;
    for (int i = 0; i < elements_.size(); ++i) {
        cloned_elements.push_back(elements_[i]->Clone());
    }
    return cloned_elements;
}

std::size_t AdditionExpression::NumberOfElements() const {
    return elements_.size();
}


