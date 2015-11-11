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
    MathElementPtr result_num = Multiply(operand_->numerator(), fraction->numerator());
    
    // Multiplying the denominators
    MathElementPtr result_den = Multiply(operand_->denominator(), fraction->denominator());
    
    // Constructing and returning a resulting Fraction
    return MathElementPtr(new Fraction(std::move(result_num), std::move(result_den)));
}

// Visit a Variable
MathElementPtr FractionMultiplicationVisitor::VisitVariable(const Variable* variable) const {
    // Multiplying the numerator by the variable
    MathElementPtr result_numerator = Multiply(operand_->numerator(), variable);
    
    // Returning the new fraction
    return MathElementPtr(new Fraction(std::move(result_numerator), operand_->ClonedDenominator()));
}

// Visit a MultiplicationExpression
MathElementPtr FractionMultiplicationVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    // Delegate to multiplication expression
    return Multiply(expression, operand_);
}

// Visit an AdditionExpression
MathElementPtr FractionMultiplicationVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    // Delegate to addition expression
    return Multiply(expression, operand_);
}