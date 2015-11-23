//
//  VariableAssignmentVisitor.hpp
//  Calculator
//
//  Created by Alexander Robau on 11/23/15.
//  Copyright © 2015 Robau inc. All rights reserved.
//

#ifndef VARIABLE_ASSIGNMENT_VISITOR_H_
#define VARIABLE_ASSIGNMENT_VISITOR_H_

#include <memory>
class MathElement;
class Variable;

typedef std::unique_ptr<MathElement> MathElementPtr;

typedef std::unique_ptr<Variable> VariablePtr;

class VariableAssignmentVisitor {
private:
    const Variable* variable_;
    const MathElement* replacement_;
    
public:
    VariableAssignmentVisitor(const Variable*, const MathElement*);
    
    bool NeedsReplacement(const Variable*) const;
    
    const Variable* variable() const;
    const MathElement* replacement() const;
    
    MathElementPtr ClonedVariable() const;
    MathElementPtr ClonedReplacement() const;
};

typedef std::shared_ptr<VariableAssignmentVisitor> VariableAssignmentVisitorPtr;

#endif // VARIABLE_ASSIGNMENT_VISITOR_H_
