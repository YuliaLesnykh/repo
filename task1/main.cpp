#include "CopySyntaxTree.hpp"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    
    Number* n32 = new Number(32.0);
    Number* n16 = new Number(16.0);
    BinaryOperation* minus = new BinaryOperation(n32, BinaryOperation::MINUS, n16);
    FunctionCall* callSqrt = new FunctionCall("sqrt", minus);
    Number* n2 = new Number(2.0);
    BinaryOperation* mult = new BinaryOperation(n2, BinaryOperation::MUL, callSqrt);
    FunctionCall* callAbs = new FunctionCall("abs", mult);
    
    cout << "Оригинал : " << callAbs->evaluate() << endl;
    
    CopySyntaxTree cst;
    Expression* newExpr = callAbs->transform(&cst);
    
    cout << "Копия : " << newExpr->evaluate() << endl;
    cout << "Адрес оригинала: " << callAbs << endl;
    cout << "Адрес копии: " << newExpr << endl;
    
    delete callAbs;
    delete newExpr;
    
    return 0;
}