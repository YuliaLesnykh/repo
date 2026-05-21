#include "FoldConstants.hpp"
#include <cmath>

Expression* FoldConstants::transformNumber(Number const* number) {
    return new Number(number->value());
}

Expression* FoldConstants::transformBinaryOperation(BinaryOperation const* binop) {
    Expression* left = binop->left()->transform(this);
    Expression* right = binop->right()->transform(this);
    
    Number* leftNum = dynamic_cast<Number*>(left);
    Number* rightNum = dynamic_cast<Number*>(right);
    
    if (leftNum && rightNum) {
        BinaryOperation temp(leftNum, binop->operation(), rightNum);
        double result = temp.evaluate();
        delete left;
        delete right;
        return new Number(result);
    }
    
    return new BinaryOperation(left, binop->operation(), right);
}

Expression* FoldConstants::transformFunctionCall(FunctionCall const* fcall) {
    Expression* arg = fcall->arg()->transform(this);
    
    Number* argNum = dynamic_cast<Number*>(arg);
    if (argNum) {
        FunctionCall temp(fcall->name(), argNum);
        double result = temp.evaluate();
        delete arg;
        return new Number(result);
    }
    
    return new FunctionCall(fcall->name(), arg);
}

Expression* FoldConstants::transformVariable(Variable const* var) {
    return new Variable(var->name());
}