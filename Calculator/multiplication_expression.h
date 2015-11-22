//
//  multiplication_expression.hpp
//  Calculator
//
//  Created by Alexander Robau on 11/1/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef MULTIPLICATION_EXPRESSION_H_
#define MULTIPLICATION_EXPRESSION_H_

#include "math_element.h"
#include "multiplication_expression_multiplication_visitor.h"
#include "multiplication_expression_division_visitor.h"
#include "multiplication_expression_addition_visitor.h"
#include "multiplication_expression_subtraction_visitor.h"

class MultiplicationExpression : public MathElement {
  private:
    std::vector<MathElementPtr> elements_;
    
  public:
    // Constructors
    explicit MultiplicationExpression(std::vector<MathElementPtr>);
    MultiplicationExpression(MathElementPtr, MathElementPtr);
    
    // MathElement overrides
    VisitorPtr CreateMultiplicationVisitor() const;
    VisitorPtr CreateDivisionVisitor() const;
    VisitorPtr CreateAdditionVisitor() const;
    VisitorPtr CreateSubtractionVisitor() const;
    EqualityVisitorPtr CreateEqualityVisitor() const;
    
    MathElementPtr Accept(const VisitorPtr) const;
    bool Accept(const EqualityVisitorPtr) const;
    
    double DoubleValue() const;
    std::string ToString() const;
    
    MathElementPtr Clone() const;
    
    // Class sepecific functions
    const std::vector<MathElementPtr>* elements() const;
    std::vector<MathElementPtr> ClonedElements() const;
    std::size_t NumberOfElements() const;
};

#endif // MULTIPLICATION_EXPRESSION_H_
