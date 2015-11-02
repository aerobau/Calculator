//
//  fraction_multiplication_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "fraction_multiplication_visitor.h"

// Constructor: sets the operand
FractionMultiplicationVisitor::FractionMultiplicationVisitor(const Fraction* operand)
    : operand_(operand) {}


// VISITING FUNCTIONS //
// Visit various types and return the multiplication of the operand and the visited value

// Visit an Integer
MathElementPtr FractionMultiplicationVisitor::VisitInteger(const Integer* integer) const {
    // Obtaining the multiplication visitor for the numerator
    Visitor* numerator_visitor = operand_->numerator()->CreateMultiplicationVisitor();
    
    // Multiplying the numerator by the integer being visited
    MathElementPtr result_numerator = numerator_visitor->VisitInteger(integer);
    
    // Constructing and returning a Fraction
    return MathElementPtr(new Fraction(std::move(result_numerator), operand_->ClonedDenominator()));
}

// Visit a Decimal
MathElementPtr FractionMultiplicationVisitor::VisitDecimal(const Decimal* decimal) const {
    // Multiplying the double values and constructing and returning a new Decimal
    double result_value = operand_->DoubleValue() * decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr FractionMultiplicationVisitor::VisitFraction(const Fraction* fraction) const {
    // Multiplying the numerators
    Visitor* operand_numerator_visitor = operand_->numerator()->CreateMultiplicationVisitor();
    MathElementPtr result_num = fraction->denominator()->Accept(operand_numerator_visitor);
    
    // Multiplying the denominators
    Visitor* operand_denominator_visitor = operand_->denominator()->CreateMultiplicationVisitor();
    MathElementPtr result_den = fraction->denominator()->Accept(operand_denominator_visitor);
    
    // Constructing and returning a resulting Fraction
    return MathElementPtr(new Fraction(std::move(result_num), std::move(result_den)));
}

// Visit a Variable
MathElementPtr FractionMultiplicationVisitor::VisitVariable(const Variable* variable) const {
    return MathElementPtr(nullptr);
}

// Visit a MultiplicationExpression
MathElementPtr FractionMultiplicationVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    // getting the cloned elements from the expression and adding on the Fraction operand
    std::vector<MathElementPtr> cloned_elements = expression->ClonedElements();
    cloned_elements.push_back(operand_->Clone());
    
    // Constructing and returning a new MultiplicationExpression
    return MathElementPtr(new MultiplicationExpression(std::move(cloned_elements)));
}