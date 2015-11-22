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
    : elements_({std::move(first), std::move(second)}) {}

// MathElement overrides //

// Visitor factory methods

Visitor* AdditionExpression::CreateMultiplicationVisitor() const {
    return new AdditionExpressionMultiplicationVisitor(this);
}

Visitor* AdditionExpression::CreateDivisionVisitor() const {
    return new AdditionExpressionDivisionVisitor(this);
}

Visitor* AdditionExpression::CreateAdditionVisitor() const {
    return new AdditionExpressionAdditionVisitor(this);
}

Visitor* AdditionExpression::CreateSubtractionVisitor() const {
    return new AdditionExpressionSubtractionVisitor(this);
}

EqualityVisitor* AdditionExpression::CreateEqualityVisitor() const {
    return new AdditionExpressionEqualityVisitor(this);
}

// Visitor acception methods

MathElementPtr AdditionExpression::Accept(const Visitor* visitor) const {
    return visitor->VisitAdditionExpression(this);
}

bool AdditionExpression::Accept(const EqualityVisitor* visitor) const {
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


