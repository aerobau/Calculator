//
//  main.cpp
//  Calculator
//
//  Created by Alexander Robau on 10/27/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#include <iostream>
#include "integer.h"
#include "decimal.h"
#include "fraction.h"
#include "variable.h"
#include "multiplication_expression.h"

MathElementPtr Multiply(MathElementPtr first, MathElementPtr second) {
    return second->Accept(first->CreateMultiplicationVisitor());
}

MathElementPtr Divide(MathElementPtr first, MathElementPtr second) {
    return second->Accept(first->CreateDivisionVisitor());
}

MathElementPtr Add(MathElementPtr first, MathElementPtr second) {
    return second->Accept(first->CreateAdditionVisitor());
}

MathElementPtr Subtract(MathElementPtr first, MathElementPtr second) {
    return second->Accept(first->CreateSubtractionVisitor());
}

MathElementPtr Assign(MathElementPtr expression, MathElementPtr replacement, char variable) {
    MathElementPtr variable_to_replace = MathElementPtr(new Variable(variable));
    return expression->Exchange(variable_to_replace.get(), replacement.get());
}

int main(int argc, const char * argv[]) {
    MathElementPtr first = MathElementPtr(new Variable('y'));
    MathElementPtr second = MathElementPtr(new Variable('x'));
    MathElementPtr third = MathElementPtr(new Integer(5));
    
    MathElementPtr div = Divide(first->Clone(), second->Clone());
    MathElementPtr div2 = Multiply(second->Clone(), second->Clone());
    MathElementPtr div3 = Add(second->Clone(), first->Clone());
    
    MathElementPtr div3assigned = Assign(div3->Clone(), MathElementPtr(new Integer(5)), 'x');
    div3assigned = Assign(div3assigned->Clone(), MathElementPtr(new Integer(7)), 'y');
    
    std::cout << div->ToString() << std::endl;
    std::cout << div2->ToString() << std::endl;
    std::cout << div3->ToString() << std::endl;
    std::cout << div3assigned->ToString() << std::endl;
    
    MathElementPtr r = Multiply(div->Clone(), third->Clone());
    
    std::cout << r->ToString() << std::endl;
    
}
