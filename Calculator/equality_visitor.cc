//
//  equality_visitor.cpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include "equality_visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"
#include "multiplication_expression.h"
#include "addition_expression.h"

IntegerEqualityVisitor::IntegerEqualityVisitor(const Integer* operand) : operand_(operand) {}

bool IntegerEqualityVisitor::VisitInteger(const Integer* integer) const {
    return operand_->value() == integer->value();
}

DecimalEqualityVisitor::DecimalEqualityVisitor(const Decimal* operand) : operand_(operand) {}

bool DecimalEqualityVisitor::VisitDecimal(const Decimal* decimal) const {
    return operand_->DoubleValue() == decimal->DoubleValue();
}

FractionEqualityVisitor::FractionEqualityVisitor(const Fraction* operand) : operand_(operand) {}

bool FractionEqualityVisitor::VisitFraction(const Fraction* fraction) const {
    EqualityVisitor* numerator_visit = operand_->numerator()->CreateEqualityVisitor();
    EqualityVisitor* denominator_visit = operand_->denominator()->CreateEqualityVisitor();
    return fraction->numerator()->Accept(numerator_visit) &&
           fraction->denominator()->Accept(denominator_visit);
}

VariableEqualityVisitor::VariableEqualityVisitor(const Variable* operand) : operand_(operand) {}

bool VariableEqualityVisitor::VisitVariable(const Variable* variable) const {
    return operand_->representation() == variable->representation();
}

MultiplicationExpressionEqualityVisitor::
MultiplicationExpressionEqualityVisitor(const MultiplicationExpression* operand)
    : operand_(operand) {}

bool MultiplicationExpressionEqualityVisitor::
VisitMultiplicationExpression(const MultiplicationExpression* expression) const {
    if (operand_->NumberOfElements() == expression->NumberOfElements()) {
        std::vector<MathElementPtr> cloned_operand_elements = operand_->ClonedElements();
        std::vector<MathElementPtr> cloned_expression_elements = expression->ClonedElements();
        for (int i = 0; i < cloned_operand_elements.size(); ++i) {
            for (int j = 0; j < cloned_expression_elements.size(); ++j) {
                if (cloned_operand_elements[i] == cloned_expression_elements[j]) {
                    cloned_expression_elements.erase(cloned_expression_elements.begin() + j);
                }
            }
        }
        if (cloned_expression_elements.size() == 0) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

AdditionExpressionEqualityVisitor::
AdditionExpressionEqualityVisitor(const AdditionExpression* operand) : operand_(operand) {}

bool AdditionExpressionEqualityVisitor::
VisitAdditionExpression(const AdditionExpression* expression) const {
    if (operand_->NumberOfElements() == expression->NumberOfElements()) {
        std::vector<MathElementPtr> cloned_operand_elements = operand_->ClonedElements();
        std::vector<MathElementPtr> cloned_expression_elements = expression->ClonedElements();
        for (int i = 0; i < cloned_operand_elements.size(); ++i) {
            for (int j = 0; j < cloned_expression_elements.size(); ++j) {
                if (cloned_operand_elements[i] == cloned_expression_elements[j]) {
                    cloned_expression_elements.erase(cloned_expression_elements.begin() + j);
                }
            }
        }
        if (cloned_expression_elements.size() == 0) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}