//
//  addition_expression_multiplication_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/4/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "addition_expression_multiplication_visitor.h"

AdditionExpressionMultiplicationVisitor::
AdditionExpressionMultiplicationVisitor(const AdditionExpression* operand) : operand_(operand) {}


// VISITING FUNCTIONS //
// Visit various types and return the multiplication of the operand and the visited value

// Visit an Integer
MathElementPtr AdditionExpressionMultiplicationVisitor::VisitInteger(const Integer* integer) const {
    // Constructing and returning a new AdditionExpression by distributing the visited element
    return DistributeMultiply(integer);
}

// Visit a Decimal
MathElementPtr AdditionExpressionMultiplicationVisitor::VisitDecimal(const Decimal* decimal) const {
    // Calculating the double result value and constructing and returning a new Decimal
    double result_value = operand_->DoubleValue() * decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

// Visit a Fraction
MathElementPtr AdditionExpressionMultiplicationVisitor::
VisitFraction(const Fraction* fraction) const {
    // Constructing and returning a new AdditionExpression by distributing the visited element
    return DistributeMultiply(fraction);
}

MathElementPtr AdditionExpressionMultiplicationVisitor::
VisitVariable(const Variable* variable) const {
    // Constructing and returning a new AdditionExpression by distributing the visited element
    return DistributeMultiply(variable);
}

// Visit a MultiplicationExpression
MathElementPtr AdditionExpressionMultiplicationVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    // Constructing and returning a new AdditionExpression by distributing the visited element
    return DistributeMultiply(expression);
}

// Visit an AdditionExpression
MathElementPtr AdditionExpressionMultiplicationVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    // Constructing and returning a new AdditionExpression by distributing the visited element
    return DistributeMultiply(expression);
}



// Class specific functions //

// Distributing method that distributes a given element to the elements of the operand
MathElementPtr AdditionExpressionMultiplicationVisitor::
DistributeMultiply(const MathElement* distributing_element) const {
    // Getting a pointer to the vector of elements from the first operand
    const std::vector<MathElementPtr>* elements = operand_->elements();
    
    // Creating a result vector, and filling it with the result of multiplying each element from the
    // addition expression operand by the integer being visited
    std::vector<MathElementPtr> result_elements;
    for (int i = 0; i < elements->size(); ++i) {
        Visitor* visitor = elements->at(i)->CreateMultiplicationVisitor();
        result_elements.push_back(distributing_element->Accept(visitor));
    }
    
    // Constructing and returning a new AdditionExpression
    return MathElementPtr(new AdditionExpression(std::move(result_elements)));
}