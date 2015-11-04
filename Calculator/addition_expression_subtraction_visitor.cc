//
//  addition_expression_subtraction_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/4/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "addition_expression_subtraction_visitor.h"

AdditionExpressionSubtractionVisitor::
AdditionExpressionSubtractionVisitor(const AdditionExpression* operand) : operand_(operand) {}

MathElementPtr AdditionExpressionSubtractionVisitor::VisitInteger(const Integer* integer) const {
    MathElementPtr negative_integer = MathElementPtr(new Integer(integer->value() * -1));
    return AddElementToOperand(negative_integer.get());
}

MathElementPtr AdditionExpressionSubtractionVisitor::VisitDecimal(const Decimal* decimal) const {
    double result_value = operand_->DoubleValue() + decimal->DoubleValue();
    return MathElementPtr(new Decimal(result_value));
}

MathElementPtr AdditionExpressionSubtractionVisitor::VisitFraction(const Fraction* fraction) const {
    MathElementPtr neg_one = MathUtilities::NegativeOne();
    MathElementPtr negative_fraction = fraction->Accept(neg_one->CreateMultiplicationVisitor());
    return AddElementToOperand(negative_fraction.get());
}

MathElementPtr AdditionExpressionSubtractionVisitor::VisitVariable(const Variable* variable) const {
    MathElementPtr neg_one = MathUtilities::NegativeOne();
    MathElementPtr negative_variable = variable->Accept(neg_one->CreateMultiplicationVisitor());
    return AddElementToOperand(negative_variable.get());
}

MathElementPtr AdditionExpressionSubtractionVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    MathElementPtr neg_one = MathUtilities::NegativeOne();
    MathElementPtr negative_expression = expression->Accept(neg_one->CreateMultiplicationVisitor());
    return AddElementToOperand(negative_expression.get());
}

MathElementPtr AdditionExpressionSubtractionVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    MathElementPtr neg_one = MathUtilities::NegativeOne();
    MathElementPtr negative_expression = expression->Accept(neg_one->CreateMultiplicationVisitor());
    return negative_expression->Accept(operand_->CreateAdditionVisitor());
}

MathElementPtr AdditionExpressionSubtractionVisitor::
AddElementToOperand(const MathElement* element) const {
    std::vector<MathElementPtr> cloned_elements = operand_->ClonedElements();
    cloned_elements.push_back(element->Clone());
    return  MathElementPtr(new AdditionExpression(std::move(cloned_elements)));
}