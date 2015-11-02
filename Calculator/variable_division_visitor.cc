//
//  variable_division_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "variable_division_visitor.h"

// Constructing and returning a new Fraction
VariableDivisionVisitor::VariableDivisionVisitor(const Variable* operand) : operand_(operand) {}


// VISITING FUNCTIONS //
// Visit various types and return the division of the operand and the visited value

// Visit an Integer
MathElementPtr VariableDivisionVisitor::VisitInteger(const Integer* integer) const {
    if (integer->Accept(MathUtilities::One()->CreateEqualityVisitor())) {
        // The integer being divided by (visited) is equal to one, return the variable
        return operand_->Clone();
    } else {
        // Constructing and returning a fraction
        return MathElementPtr(new Fraction(operand_->Clone(), integer->Clone()));
    }
}

// Visit a Decimal
MathElementPtr VariableDivisionVisitor::VisitDecimal(const Decimal* decimal) const {
    double result_value = operand_->DoubleValue() / decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr VariableDivisionVisitor::VisitFraction(const Fraction* fraction) const {
    // Getting the result numerator by multiplying the variable by the denominator
    MathElementPtr result_numerator = fraction->denominator()->Accept(this);
    
    // Constructing and returning a fraction, putting the fraction numerator as the new denominator
    return MathElementPtr(new Fraction(std::move(result_numerator), fraction->ClonedNumerator()));
}

// Visit a Variable
MathElementPtr VariableDivisionVisitor::VisitVariable(const Variable* variable) const {
    if (variable->Accept(operand_->CreateEqualityVisitor())) {
        // the variables are equal, one over another is simply 1
        return MathUtilities::One();
    } else {
        // Variables not the same, create a new Fraction
        return MathElementPtr(new Fraction(operand_->Clone(), variable->Clone()));
    }
}

// Visit a MultiplicationExpression
MathElementPtr VariableDivisionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    // Construct and return a new Fraction
    return MathElementPtr(new Fraction(operand_->Clone(), expression->Clone()));
}