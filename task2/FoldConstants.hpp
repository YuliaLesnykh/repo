#ifndef FOLD_CONSTANTS_HPP
#define FOLD_CONSTANTS_HPP

#include "Expression.hpp" 

struct FoldConstants : Transformer {
    Expression* transformNumber(Number const* number) override;
    Expression* transformBinaryOperation(BinaryOperation const* binop) override;
    Expression* transformFunctionCall(FunctionCall const* fcall) override;
    Expression* transformVariable(Variable const* var) override;
};

#endif