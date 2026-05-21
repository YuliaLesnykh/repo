#include "Ingredients.hpp"
#include "Ingredient.hpp"

// Mushrooms
double Mushrooms::getWeight() const { return 500.0; }
double Mushrooms::getCaloriesPer100g() const { return 27.0; }
double Mushrooms::getProteinPer100g() const { return 4.4; }
double Mushrooms::getFatPer100g() const { return 1.0; }
double Mushrooms::getCarbsPer100g() const { return 0.2; }
double Mushrooms::getCostPer100g() const { return 20.0; }
void Mushrooms::accept(IngredientVisitor* visitor) const { visitor->visit(this); }

// Shrimps
double Shrimps::getWeight() const { return 100.0; }
double Shrimps::getCaloriesPer100g() const { return 83.0; }
double Shrimps::getProteinPer100g() const { return 18.0; }
double Shrimps::getFatPer100g() const { return 1.0; }
double Shrimps::getCarbsPer100g() const { return 0.0; }
double Shrimps::getCostPer100g() const { return 50.0; }
void Shrimps::accept(IngredientVisitor* visitor) const { visitor->visit(this); }

// SourCream
double SourCream::getWeight() const { return 30.0; }
double SourCream::getCaloriesPer100g() const { return 120.0; }
double SourCream::getProteinPer100g() const { return 3.3; }
double SourCream::getFatPer100g() const { return 10.0; }
double SourCream::getCarbsPer100g() const { return 3.3; }
double SourCream::getCostPer100g() const { return 14.4; }
void SourCream::accept(IngredientVisitor* visitor) const { visitor->visit(this); }

// Cheese
double Cheese::getWeight() const { return 20.0; }
double Cheese::getCaloriesPer100g() const { return 345.0; }
double Cheese::getProteinPer100g() const { return 25.0; }
double Cheese::getFatPer100g() const { return 25.0; }
double Cheese::getCarbsPer100g() const { return 0.0; }
double Cheese::getCostPer100g() const { return 70.0; }
void Cheese::accept(IngredientVisitor* visitor) const { visitor->visit(this); }

// DillAndSpices
double DillAndSpices::getWeight() const { return 30.0; }
double DillAndSpices::getCaloriesPer100g() const { return 37.0; }
double DillAndSpices::getProteinPer100g() const { return 3.3; }
double DillAndSpices::getFatPer100g() const { return 0.0; }
double DillAndSpices::getCarbsPer100g() const { return 7.0; }
double DillAndSpices::getCostPer100g() const { return 20.0; }
void DillAndSpices::accept(IngredientVisitor* visitor) const { visitor->visit(this); }
