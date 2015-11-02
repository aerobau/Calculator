//
//  integer_division_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "integer_division_visitor.h"

// Constructor: sets the operand
IntegerDivisionVisitor::IntegerDivisionVisitor(const Integer* operand) : operand_(operand) {}


// VISITING FUNCTIONS //
// Visit various types and return the division of the operand and the visited value

// Visit an Integer
MathElementPtr IntegerDivisionVisitor::VisitInteger(const Integer* integer) const {
    if (operand_->value() % integer->value() == 0) {
        return MathElementPtr(new Integer(operand_->value() / integer->value()));
    } else {
        // Find the greatest common denominator of the two integers
        int numerator_int = operand_->value(), denominator_int = integer->value();
        int gcd = MathUtilities::GCD(numerator_int, denominator_int);
        numerator_int /= gcd, denominator_int /= gcd;
        
        // Make numerator and denominator after dividing out the gcd
        MathElementPtr numerator = MathElementPtr(new Integer(numerator_int));
        MathElementPtr denominator = MathElementPtr(new Integer(denominator_int));
        
        // Construct and return Fraction
        return MathElementPtr(new Fraction(std::move(numerator), std::move(denominator)));
    }
}

// Visit a Decimal
MathElementPtr IntegerDivisionVisitor::VisitDecimal (const Decimal* decimal) const {
    // getting the result value and constructing and returning a Decimal
    double result_value = operand_->DoubleValue() / decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr IntegerDivisionVisitor::VisitFraction(const Fraction* fraction) const {
    // Getting the denominator and multiplying it by this visitor
    MathElementPtr result_numerator = fraction->denominator()->Accept(this);
    
    // Putting the fraction numerator on the bottom and the new multiplied numerator on top, inverse
    // for the division, and then constructing and returning the Fraction
    return MathElementPtr(new Fraction(std::move(result_numerator), fraction->ClonedNumerator()));
}

// Visit a Variable
MathElementPtr IntegerDivisionVisitor::VisitVariable(const Variable* variable) const {
    return MathElementPtr(new Fraction(operand_->Clone(), variable->Clone()));
}

// Visit a MultiplicationExpression
MathElementPtr IntegerDivisionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    // Constructing and returning a new Fraction
    return MathElementPtr(new Fraction(operand_->Clone(), expression->Clone()));
}