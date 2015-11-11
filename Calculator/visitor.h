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
class AdditionExpression;
typedef std::unique_ptr<MathElement> MathElementPtr;

class Visitor {
  public:
    // VISITING METHODS //
    // Visitation methods for all of the different types that are suppported for symbolic
    // representation by the calculator, note that they all take constant pointers, the ownership
    // of the objects will be elsewhere.  These are meant to be overriden and depending on the
    // visitor subclass, which is specific to element subclass and function being performed, the
    // proper function will be performed.
    
    virtual MathElementPtr VisitInteger(const Integer*) const { return MathElementPtr(nullptr); }
    virtual MathElementPtr VisitDecimal(const Decimal*) const { return MathElementPtr(nullptr); }
    virtual MathElementPtr VisitFraction(const Fraction*) const { return MathElementPtr(nullptr); }
    virtual MathElementPtr VisitVariable(const Variable*) const { return MathElementPtr(nullptr); };
    virtual MathElementPtr VisitMultiplicationExpression(const MultiplicationExpression*) const { return MathElementPtr(nullptr); };
    virtual MathElementPtr VisitAdditionExpression(const AdditionExpression*) const { return MathElementPtr(nullptr); };
    
protected:
    // VISITOR SPECIFIC HELPER METHODS //
    // Helper methods for all visitor subclasses that will multiply two constant MathElement
    // pointers, note that the actual ownership of the objects will be elsewhere by unique_ptr
    // conventions, these methods are final and implemented in the cpp file for visitor
    
    MathElementPtr Multiply(const MathElement*, const MathElement*) const;
    MathElementPtr Divide(const MathElement*, const MathElement*) const;
    MathElementPtr Add(const MathElement*, const MathElement*) const;
    MathElementPtr Subtract(const MathElement*, const MathElement*) const;
    bool Equal(const MathElement*, const MathElement*) const;
};

#endif // VISITOR_H_
