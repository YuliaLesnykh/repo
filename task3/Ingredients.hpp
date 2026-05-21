#ifndef INGREDIENTS_HPP
#define INGREDIENTS_HPP

#include "Ingredient.hpp"

struct Mushrooms : Ingredient {
    double getWeight() const override;
    double getCaloriesPer100g() const override;
    double getProteinPer100g() const override;
    double getFatPer100g() const override;
    double getCarbsPer100g() const override;
    double getCostPer100g() const override;
    void accept(IngredientVisitor* visitor) const override;
};

struct Shrimps : Ingredient {
    double getWeight() const override;
    double getCaloriesPer100g() const override;
    double getProteinPer100g() const override;
    double getFatPer100g() const override;
    double getCarbsPer100g() const override;
    double getCostPer100g() const override;
    void accept(IngredientVisitor* visitor) const override;
};

struct SourCream : Ingredient {
    double getWeight() const override;
    double getCaloriesPer100g() const override;
    double getProteinPer100g() const override;
    double getFatPer100g() const override;
    double getCarbsPer100g() const override;
    double getCostPer100g() const override;
    void accept(IngredientVisitor* visitor) const override;
};

struct Cheese : Ingredient {
    double getWeight() const override;
    double getCaloriesPer100g() const override;
    double getProteinPer100g() const override;
    double getFatPer100g() const override;
    double getCarbsPer100g() const override;
    double getCostPer100g() const override;
    void accept(IngredientVisitor* visitor) const override;
};

struct DillAndSpices : Ingredient {
    double getWeight() const override;
    double getCaloriesPer100g() const override;
    double getProteinPer100g() const override;
    double getFatPer100g() const override;
    double getCarbsPer100g() const override;
    double getCostPer100g() const override;
    void accept(IngredientVisitor* visitor) const override;
};

#endif