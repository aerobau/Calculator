//
//  multiplication_expression_division_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "multiplication_expression_division_visitor.h"

MultiplicationExpressionDivisionVisitor::
MultiplicationExpressionDivisionVisitor(const MultiplicationExpression* operand)
    : operand_(operand) {}


// VISITING FUNCTIONS //
// Visit various types and return the division of the operand and the visited value

// Visit an Integer
MathElementPtr MultiplicationExpressionDivisionVisitor::VisitInteger(const Integer* integer) const {
    // Construct and return a new Fraction
    return MathElementPtr(new Fraction(operand_->Clone(), integer->Clone()));
}

// Visit a Decimal
MathElementPtr MultiplicationExpressionDivisionVisitor::VisitDecimal(const Decimal* decimal) const {
    // Calculate the double value and construct and return a new decimal
    double result_value = operand_->DoubleValue() / decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr MultiplicationExpressionDivisionVisitor::
VisitFraction(const Fraction* fraction) const {
    // Multiply by the denominator, make the numerator the denominator of new constructed fraction
    MathElementPtr result_numerator = fraction->denominator()->Accept(this);
    return MathElementPtr(new Fraction(std::move(result_numerator), fraction->ClonedNumerator()));
}

// Visit a Variable
MathElementPtr MultiplicationExpressionDivisionVisitor::
VisitVariable(const Variable* variable) const {
    // Construct and return a new Fraction
    return MathElementPtr(new Fraction(operand_->Clone(), variable->Clone()));
}

// Visit a MultiplicationExpression
MathElementPtr MultiplicationExpressionDivisionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    // Construct and return a new Fraction
    return MathElementPtr(new Fraction(operand_->Clone(), expression->Clone()));
}

// Visit an AdditionExpression
MathElementPtr MultiplicationExpressionDivisionVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    // Check to see if any of the elements of the MultiplicationExpression operand are equal to the
    // addition expression being divided by
    for (unsigned int i = 0; i < operand_->elements()->size(); ++i) {
        if (Equal(operand_->elements()->at(i).get(), expression)) {
            // An equla one was found, simply remove it from the operand and return a new
            // MultiplicationExpression withput the removed element.
            std::vector<MathElementPtr> cloned_elements = operand_->ClonedElements();
            cloned_elements.erase(cloned_elements.begin() + i);
            return MathElementPtr(new MultiplicationExpression(std::move(cloned_elements)));
        }
    }
    // No equal elements were found, ust make the fraction
    return MathElementPtr(new Fraction(operand_->Clone(), expression->Clone()));
}