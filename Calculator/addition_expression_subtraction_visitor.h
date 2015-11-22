//
//  addition_expression_subtraction_visitor.hpp
//  Calculator
//
//  Created by Alexander Robau on 11/4/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef ADDITION_EXPRESSION_SUBTRACTION_VISITOR_H_
#define ADDITION_EXPRESSION_SUBTRACTION_VISITOR_H_

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"
#include "multiplication_expression.h"
#include "addition_expression.h"

class AdditionExpressionSubtractionVisitor : public Visitor {
  private:
    // Storage for the first operand
    const AdditionExpression* operand_;
    
    MathElementPtr AddNegation(const MathElement*) const;
    
  public:
    // Constructor
    AdditionExpressionSubtractionVisitor(const AdditionExpression*);
    
    // Visitor overrides
    MathElementPtr VisitInteger(const Integer*) const;
    MathElementPtr VisitDecimal(const Decimal*) const;
    MathElementPtr VisitFraction(const Fraction*) const;
    MathElementPtr VisitVariable(const Variable*) const;
    MathElementPtr VisitExponent(const Exponent*) const;
    MathElementPtr VisitMultiplicationExpression(const MultiplicationExpression*) const;
    MathElementPtr VisitAdditionExpression(const AdditionExpression*) const;
};

#endif // ADDITION_EXPRESSION_SUBTRACTION_VISITOR_H_
