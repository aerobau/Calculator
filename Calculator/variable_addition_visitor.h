//
//  variable_addition_visitor.hpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef VARIABLE_ADDITION_VISITOR_H_
#define VARIABLE_ADDITION_VISITOR_H_

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"

class VariableAdditionVisitor : public Visitor {
private:
    const Variable* operand_;
    
public:
    VariableAdditionVisitor(const Variable*);
    
    MathElementPtr VisitInteger(const Integer*) const;
    MathElementPtr VisitDecimal(const Decimal*) const;
    MathElementPtr VisitFraction(const Fraction*) const;
    MathElementPtr VisitVariable(const Variable*) const;
    // TODO: Create VisitMultiplicationExpression (requires AdditionExpression)
};

#endif // VARIABLE_ADDITION_VISITOR_H_
