#ifndef NUTRITION_CALCULATOR_HPP
#define NUTRITION_CALCULATOR_HPP

#include "Ingredient.hpp"

struct NutritionCalculator : IngredientVisitor {
    double totalCalories = 0;
    double totalProtein = 0;
    double totalFat = 0;
    double totalCarbs = 0;
    double totalCost = 0;
    
    void visit(Mushrooms const* m) override;
    void visit(Shrimps const* s) override;
    void visit(SourCream const* sc) override;
    void visit(Cheese const* c) override;
    void visit(DillAndSpices const* d) override;
};

#endif