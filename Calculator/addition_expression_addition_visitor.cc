//
//  addition_expression_addition_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/4/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "addition_expression_addition_visitor.h"

AdditionExpressionAdditionVisitor::
AdditionExpressionAdditionVisitor(const AdditionExpression* operand) : operand_(operand) {}


// VISITING FUNCTIONS //
// Visit various types and return the multiplication of the operand and the visited value

// Visit an Integer
MathElementPtr AdditionExpressionAdditionVisitor::VisitInteger(const Integer* integer) const {
    // Adding the element onto the operand and returning the new addition expression
    return AddElementToOperand(integer);
}

// Visit a Decimal
MathElementPtr AdditionExpressionAdditionVisitor::VisitDecimal(const Decimal* decimal) const {
    // Calculating the double value of the result and constructing and returning a new Decimal
    double result_value = operand_->DoubleValue() + decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr AdditionExpressionAdditionVisitor::VisitFraction(const Fraction* fraction) const {
    // Adding the element onto the operand and returning the new addition expression
    return AddElementToOperand(fraction);
}

// Visit a Variable
MathElementPtr AdditionExpressionAdditionVisitor::VisitVariable(const Variable* variable) const {
    // Adding the element onto the operand and returning the new addition expression
    return AddElementToOperand(variable);
}

// Visit a MultiplicationExpression
MathElementPtr AdditionExpressionAdditionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    // Adding the element onto the operand and returning the new addition expression
    return AddElementToOperand(expression);
}

MathElementPtr AdditionExpressionAdditionVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    // Getting the cloned elements of the operand and the expression.
    std::vector<MathElementPtr> cloned_elements_operand = operand_->ClonedElements();
    std::vector<MathElementPtr> cloned_elements_expression = expression->ClonedElements();
    
    // Adding all of the elements in the expression to the operand's elements
    for (int i = 0; i < cloned_elements_expression.size(); ++i) {
        cloned_elements_operand.push_back(std::move(cloned_elements_expression[i]));
    }
    
    // Constructing and returning a new addition expression
    return MathElementPtr(new AdditionExpression(std::move(cloned_elements_operand)));
}

// Class specific functions //

// Function to simply add an element to the operand's elements //
MathElementPtr AdditionExpressionAdditionVisitor::
AddElementToOperand(const MathElement* element) const {
    // Getting the cloned elements and adding the clone of the adding element to them
    std::vector<MathElementPtr> cloned_elements = operand_->ClonedElements();
    cloned_elements.push_back(element->Clone());
    
    // Constructing and returning a new AdditionExpression from the cloned elements
    return MathElementPtr(new AdditionExpression(std::move(cloned_elements)));
}