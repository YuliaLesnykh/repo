#ifndef RECIPE_HPP
#define RECIPE_HPP

#include <vector>
#include "Ingredient.hpp"

struct Recipe {
    void addIngredient(Ingredient const* ing);
    void accept(IngredientVisitor* visitor) const;
    ~Recipe();
private:
    std::vector<Ingredient const*> ingredients;
};

#endif