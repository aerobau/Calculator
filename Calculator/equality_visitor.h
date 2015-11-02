//
//  equality_visitor.hpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef EQUALTIY_VISITOR_H_
#define EQUALTIY_VISITOR_H_

class MathElement;
class Integer;
class Decimal;
class Fraction;
class Variable;
class MultiplicationExpression;

class EqualityVisitor {
  public:
    virtual bool VisitInteger(const Integer*) const { return false; }
    virtual bool VisitDecimal(const Decimal*) const { return false; }
    virtual bool VisitFraction(const Fraction*) const { return false; }
    virtual bool VisitVariable(const Variable*) const { return false; }
    virtual bool VisitMultiplicationExpression(const MultiplicationExpression*) const { return false; }
};

class IntegerEqualityVisitor : public EqualityVisitor {
  private:
    // Storage for the first operand
    const Integer* operand_;
    
  public:
    // Constructor
    IntegerEqualityVisitor(const Integer*);
    
    // EqualityVisitor overrides
    bool VisitInteger(const Integer*) const;
};

class DecimalEqualityVisitor : public EqualityVisitor {
  private:
    // Storage for the first operand
    const Decimal* operand_;
    
  public:
    // Constructor
    DecimalEqualityVisitor(const Decimal*);
    
    // EqualityVisitor overrides
    bool VisitDecimal(const Decimal*) const;
};

class FractionEqualityVisitor: public EqualityVisitor {
  private:
    // Storage for the first operand
    const Fraction* operand_;
    
  public:
    // Constructor
    FractionEqualityVisitor(const Fraction*);
    
    // EqualityVisitor overrides
    bool VisitFraction(const Fraction*) const;
};

class VariableEqualityVisitor : public EqualityVisitor {
private:
    // Storage for the first operand
    const Variable* operand_;
    
public:
    // Constructor
    VariableEqualityVisitor(const Variable*);
    
    // EqualityVisitor overrides
    bool VisitVariable(const Variable*) const;
};

class MultiplicationExpressionEqualityVisitor: public EqualityVisitor {
  private:
    // Storage for the first operand
    const MultiplicationExpression* operand_;
    
  public:
    // Constructor
    MultiplicationExpressionEqualityVisitor(const MultiplicationExpression*);
    
    // EqualityVisitor overrides
    bool VisitMultiplicationExpression(const MultiplicationExpression*) const;
};

#endif // EQUALITY_VISITOR_H_
