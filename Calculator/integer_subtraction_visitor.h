//
//  integer_subtraction_visitor.hpp
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef INTEGER_SUBTRACTION_VISITOR_H_
#define INTEGER_SUBTRACTION_VISITOR_H_

#include "visitor.h"
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"

class IntegerSubtractionVisitor: public Visitor {
private:
    const Integer* operand_;
    
    MathElementPtr AddNegation(const MathElement*) const;
    
public:
    // Constructor
    IntegerSubtractionVisitor(const Integer*);
    
    MathElementPtr VisitInteger(const Integer*) const;
    MathElementPtr VisitDecimal(const Decimal*) const;
    MathElementPtr VisitFraction(const Fraction*) const;
    MathElementPtr VisitVariable(const Variable*) const;
    MathElementPtr VisitMultiplicationExpression(const MultiplicationExpression*) const;
    MathElementPtr VisitAdditionExpression(const AdditionExpression*) const;
};

#endif // INTEGER_SUBTRACTION_VISITOR_H_
