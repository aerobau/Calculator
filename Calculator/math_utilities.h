//
//  math_utilities.h
//  Calculator
//
//  Created by Alexander Robau on 10/31/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef MATH_UTILITIES_H_
#define MATH_UTILITIES_H_

#include "integer.h"

class MathUtilities {
  public:
    static MathElementPtr One() {
        return MathElementPtr(new Integer(1));
    }
    
    static MathElementPtr Zero() {
        return MathElementPtr(new Integer(0));
    }
    
    static int GCD(int first, int second) {
        return second == 0 ? first : GCD(second, first % second);
    }
};


#endif // MATH_UTITLTIES_H_
