//
//  Header.h
//  Calculator
//
//  Created by Alexander Robau on 10/30/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef VISITOR_H_
#define VISITOR_H_

#include <memory>
#include <vector>

class MathElement;
class Integer;
class Decimal;
class Fraction;
class Variable;
class MultiplicationExpression;
typedef std::unique_ptr<MathElement> MathElementPtr;

class Visitor {
  public:
    virtual MathElementPtr VisitInteger(const Integer*) const { return MathElementPtr(nullptr); }
    virtual MathElementPtr VisitDecimal(const Decimal*) const { return MathElementPtr(nullptr); }
    virtual MathElementPtr VisitFraction(const Fraction*) const { return MathElementPtr(nullptr); }
    virtual MathElementPtr VisitVariable(const Variable*) const { return MathElementPtr(nullptr); };
    virtual MathElementPtr VisitMultiplicationExpression(const MultiplicationExpression*) const { return MathElementPtr(nullptr); };
};

#endif // VISITOR_H_
