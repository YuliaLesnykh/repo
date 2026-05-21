#include "FoldConstants.hpp"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    
    Number* n32 = new Number(32.0);
    Number* n16 = new Number(16.0);
    BinaryOperation* minus = new BinaryOperation(n32, BinaryOperation::MINUS, n16);
    FunctionCall* callSqrt = new FunctionCall("sqrt", minus);
    
    cout << "До свёртки: sqrt(32 - 16) = " << callSqrt->evaluate() << endl;
    
    Variable* var = new Variable("var");
    BinaryOperation* mult = new BinaryOperation(var, BinaryOperation::MUL, callSqrt);
    FunctionCall* callAbs = new FunctionCall("abs", mult);
    
    cout << "Исходное выражение evaluate() = " << callAbs->evaluate() << endl;
    
    FoldConstants fc;
    Expression* foldedExpr = callAbs->transform(&fc);
    
    cout << "После свёртки констант evaluate() = " << foldedExpr->evaluate() << endl;
    cout << "\nПроверка свёртки: выражение упростилось" << endl;
    
    delete callAbs;
    delete foldedExpr;
    
    return 0;
}