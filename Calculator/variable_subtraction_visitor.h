//
//  variable_subtraction_visitor.hpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef VARIABLE_SUBTRACTION_VISITOR_H_
#define VARIABLE_SUBTRACTION_VISITOR_H_

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"

class VariableSubtractionVisitor : public Visitor {
private:
    const Variable* operand_;
    
    MathElementPtr AddNegation(const MathElement*) const;
    
public:
    VariableSubtractionVisitor(const Variable*);
    
    MathElementPtr VisitInteger(const Integer*) const;
    MathElementPtr VisitDecimal(const Decimal*) const;
    MathElementPtr VisitFraction(const Fraction*) const;
    MathElementPtr VisitVariable(const Variable*) const;
    MathElementPtr VisitMultiplicationExpression(const MultiplicationExpression*) const;
    MathElementPtr VisitAdditionExpression(const AdditionExpression*) const;
};
#endif /* variable_subtraction_visitor_hpp */
