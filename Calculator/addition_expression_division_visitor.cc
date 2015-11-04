//
//  addition_expression_division_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/4/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "addition_expression_division_visitor.h"

AdditionExpressionDivisionVisitor::
AdditionExpressionDivisionVisitor(const AdditionExpression* operand) : operand_(operand) {}


// VISITING FUNCTIONS //
// Visit various types and return the multiplication of the operand and the visited value

// Visit an Integer
MathElementPtr AdditionExpressionDivisionVisitor::VisitInteger(const Integer* integer) const {
    // Divide by each element individually and return the result
    return DistributeDivide(integer);
}

MathElementPtr AdditionExpressionDivisionVisitor::VisitDecimal(const Decimal* decimal) const {
    // Calculate the double value of the result and construct and return a new Decimal
    double result_value = operand_->DoubleValue() / decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

MathElementPtr AdditionExpressionDivisionVisitor::VisitFraction(const Fraction* fraction) const {
    // Divide by each element individually and return the result
    return DistributeDivide(fraction);
}

MathElementPtr AdditionExpressionDivisionVisitor::VisitVariable(const Variable* variable) const {
    // Divide by each element individually and return the result
    return DistributeDivide(variable);
}

MathElementPtr AdditionExpressionDivisionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    // Divide by each element individually and return the result
    return DistributeDivide(expression);
}

MathElementPtr AdditionExpressionDivisionVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    // Divide by each element individually and return the result
    return DistributeDivide(expression);
}


// Class specific functions //

// Function to distribute the a math element and divide all of the elements in the addition visitor
// by it individually
MathElementPtr AdditionExpressionDivisionVisitor::
DistributeDivide(const MathElement* distributing_element) const {
    // Getting a pointer to the vector of elements from the first operand
    const std::vector<MathElementPtr>* elements = operand_->elements();
    
    // Creating a result vector, and filling it with the result of multiplying each element from the
    // addition expression operand by the integer being visited
    std::vector<MathElementPtr> result_elements;
    for (int i = 0; i < elements->size(); ++i) {
        Visitor* visitor = elements->at(i)->CreateDivisionVisitor();
        result_elements.push_back(distributing_element->Accept(visitor));
    }
    
    // Constructing and returning a new AdditionExpression
    return MathElementPtr(new AdditionExpression(std::move(result_elements)));
}