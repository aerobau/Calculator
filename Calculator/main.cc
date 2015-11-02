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

int main(int argc, const char * argv[]) {
    MathElementPtr first = MathElementPtr(new Integer(1));
    MathElementPtr second = MathElementPtr(new Variable('x'));
    MathElementPtr third = MathElementPtr(new Integer(5));
    
    MathElementPtr div = Divide(first->Clone(), second->Clone());
    MathElementPtr div2 = Divide(second->Clone(), second->Clone());
    MathElementPtr div3 = Divide(second->Clone(), first->Clone());
    
    std::cout << div->ToString() << std::endl;
    std::cout << div2->ToString() << std::endl;
    std::cout << div3->ToString() << std::endl;
    
    MathElementPtr r = Multiply(div->Clone(), third->Clone());
    
    std::cout << r->ToString() << std::endl;
    
}
