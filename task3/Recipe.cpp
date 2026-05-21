#include "Recipe.hpp"

void Recipe::addIngredient(Ingredient const* ing) {
    ingredients.push_back(ing);
}

void Recipe::accept(IngredientVisitor* visitor) const {
    for (auto ing : ingredients) {
        ing->accept(visitor);
    }
}

Recipe::~Recipe() {
    for (auto ing : ingredients) {
        delete ing;
    }
}