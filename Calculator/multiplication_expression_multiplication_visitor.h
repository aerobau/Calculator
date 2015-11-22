//
//  multiplication_expression_multiplication_visitor.hpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef MULTIPLICATION_EXPRESSION_MULTIPLICATION_VISITOR_H_
#define MULTIPLICATION_EXPRESSION_MULTIPLICATION_VISITOR_H_

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"
#include "multiplication_expression.h"
#include "addition_expression.h"

class MultiplicationExpressionMultiplicationVisitor : public Visitor {
  private:
    // Storage for the first operand
    const MultiplicationExpression* operand_;
    
    // Class specific helpers
    MathElementPtr AddElementToOperand(const MathElement*) const;
    MathElementPtr AddElementsToOperand(const std::vector<MathElementPtr>*) const;
  public:
    // Constructor
    MultiplicationExpressionMultiplicationVisitor(const MultiplicationExpression*);
    
    // Visitor overrides
    MathElementPtr VisitInteger(const Integer*) const;
    MathElementPtr VisitDecimal(const Decimal*) const;
    MathElementPtr VisitFraction(const Fraction*) const;
    MathElementPtr VisitVariable(const Variable*) const;
    MathElementPtr VisitExponent(const Exponent*) const;
    MathElementPtr VisitMultiplicationExpression(const MultiplicationExpression*) const;
    MathElementPtr VisitAdditionExpression(const AdditionExpression*) const;
};

#endif // MULTIPLICATION_EXPRESSION_MULTIPLICATION_VISITOR_H_
