//
//  multiplication_expression_multiplication_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "multiplication_expression_multiplication_visitor.h"

// Constructor: sets the operand
MultiplicationExpressionMultiplicationVisitor::
MultiplicationExpressionMultiplicationVisitor(const MultiplicationExpression* operand)
    : operand_(operand) {}

// VISITING FUNCTIONS //
// Visit various types and return the multiplication of the operand and the visited value

// Visit an Integer
MathElementPtr MultiplicationExpressionMultiplicationVisitor::
VisitInteger(const Integer* integer) const {
    // Getting the elemetns from the operand and adding the addtional integer
    std::vector<MathElementPtr> cloned_elements = operand_->ClonedElements();
    cloned_elements.push_back(integer->Clone());
    
    // Constructing and returning a multiplciation expression witht he included integer
    return MathElementPtr(new MultiplicationExpression(std::move(cloned_elements)));
}

// Visit a Decimal
MathElementPtr MultiplicationExpressionMultiplicationVisitor::
VisitDecimal(const Decimal* decimal) const {
    // Getting the double result value and constructing and returning a new Decimal
    double result_value = operand_->DoubleValue() * decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr MultiplicationExpressionMultiplicationVisitor::
VisitFraction(const Fraction* fraction) const {
    // Getting the result's numerator by multiplying the operand by the fraction's numerator
    MathElementPtr result_numerator = fraction->numerator()->Accept(this);
    
    // Constructing and returning a new Fraction
    return MathElementPtr(new Fraction(std::move(result_numerator), fraction->ClonedDenominator()));
}

// Visit a Variable
MathElementPtr MultiplicationExpressionMultiplicationVisitor::
VisitVariable(const Variable* variable) const {
    // Getting the elemetns from the operand and adding the addtional integer
    std::vector<MathElementPtr> cloned_elements = operand_->ClonedElements();
    cloned_elements.push_back(variable->Clone());
    
    // Constructing and returning a multiplciation expression with the included variable
    return MathElementPtr(new MultiplicationExpression(std::move(cloned_elements)));
}

// Visit a MultiplicationExpression
MathElementPtr MultiplicationExpressionMultiplicationVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    // Getting the elements from the operand and expression
    std::vector<MathElementPtr> cloned_elements = operand_->ClonedElements();
    std::vector<MathElementPtr> cloned_expression_elements = expression->ClonedElements();
    
    // Adding all of the elements from the expression to the operand cloned elements
    for (int i = 0; i < cloned_expression_elements.size(); ++i) {
        cloned_elements.push_back(std::move(cloned_expression_elements[i]));
    }
    
    // Constructing and returning a multiplciation expression with the additional elements
    return MathElementPtr(new MultiplicationExpression(std::move(cloned_elements)));
}

