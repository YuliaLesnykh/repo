#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

// Иерархия Expression

struct Transformer;

struct Expression {
    virtual ~Expression() {}
    virtual double evaluate() const = 0;
    virtual Expression* transform(Transformer* tr) const = 0;
};

struct Transformer {
    virtual ~Transformer() {}
    virtual Expression* transformNumber(class Number const*) = 0;
    virtual Expression* transformBinaryOperation(class BinaryOperation const*) = 0;
    virtual Expression* transformFunctionCall(class FunctionCall const*) = 0;
    virtual Expression* transformVariable(class Variable const*) = 0;
};

// Number
struct Number : Expression {
    Number(double value) : value_(value) {}
    double value() const { return value_; }
    double evaluate() const { return value_; }
    Expression* transform(Transformer* tr) const {
        return tr->transformNumber(this);
    }
private:
    double value_;
};

// BinaryOperation
struct BinaryOperation : Expression {
    enum {
        PLUS = '+',
        MINUS = '-',
        DIV = '/',
        MUL = '*'
    };

    BinaryOperation(Expression const* left, int op, Expression const* right)
        : left_(left), op_(op), right_(right) {
        assert(left_ && right_);
    }

    ~BinaryOperation() {
        delete left_;
        delete right_;
    }

    double evaluate() const {
        double left = left_->evaluate();
        double right = right_->evaluate();
        switch (op_) {
        case PLUS: return left + right;
        case MINUS: return left - right;
        case DIV: return left / right;
        case MUL: return left * right;
        default: return 0.0;
        }
    }

    Expression* transform(Transformer* tr) const {
        return tr->transformBinaryOperation(this);
    }

    Expression const* left() const { return left_; }
    Expression const* right() const { return right_; }
    int operation() const { return op_; }

private:
    Expression const* left_;
    Expression const* right_;
    int op_;
};

// FunctionCall
struct FunctionCall : Expression {
    FunctionCall(std::string const& name, Expression const* arg)
        : name_(name), arg_(arg) {
        assert(arg_);
        assert(name_ == "sqrt" || name_ == "abs");
    }

    ~FunctionCall() {
        delete arg_;
    }

    double evaluate() const {
        if (name_ == "sqrt")
            return sqrt(arg_->evaluate());
        else
            return fabs(arg_->evaluate());
    }

    Expression* transform(Transformer* tr) const {
        return tr->transformFunctionCall(this);
    }

    std::string const& name() const { return name_; }
    Expression const* arg() const { return arg_; }

private:
    std::string const name_;
    Expression const* arg_;
};

// Variable
struct Variable : Expression {
    Variable(std::string const& name) : name_(name) {}

    std::string const& name() const { return name_; }
    double evaluate() const { return 0.0; }

    Expression* transform(Transformer* tr) const {
        return tr->transformVariable(this);
    }

private:
    std::string const name_;
};

// Задание 2: FoldConstants

struct FoldConstants : Transformer {
    Expression* transformNumber(Number const* number) override {
        return new Number(number->value());
    }

    Expression* transformBinaryOperation(BinaryOperation const* binop) override {
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

    Expression* transformFunctionCall(FunctionCall const* fcall) override {
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

    Expression* transformVariable(Variable const* var) override {
        return new Variable(var->name());
    }
};

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