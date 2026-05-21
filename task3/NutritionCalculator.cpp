#include "NutritionCalculator.hpp"
#include "Ingredients.hpp"

void NutritionCalculator::visit(Mushrooms const* m) {
    double ratio = m->getWeight() / 100.0;
    totalCalories += m->getCaloriesPer100g() * ratio;
    totalProtein += m->getProteinPer100g() * ratio;
    totalFat += m->getFatPer100g() * ratio;
    totalCarbs += m->getCarbsPer100g() * ratio;
    totalCost += m->getCostPer100g() * ratio;
}

void NutritionCalculator::visit(Shrimps const* s) {
    double ratio = s->getWeight() / 100.0;
    totalCalories += s->getCaloriesPer100g() * ratio;
    totalProtein += s->getProteinPer100g() * ratio;
    totalFat += s->getFatPer100g() * ratio;
    totalCarbs += s->getCarbsPer100g() * ratio;
    totalCost += s->getCostPer100g() * ratio;
}

void NutritionCalculator::visit(SourCream const* sc) {
    double ratio = sc->getWeight() / 100.0;
    totalCalories += sc->getCaloriesPer100g() * ratio;
    totalProtein += sc->getProteinPer100g() * ratio;
    totalFat += sc->getFatPer100g() * ratio;
    totalCarbs += sc->getCarbsPer100g() * ratio;
    totalCost += sc->getCostPer100g() * ratio;
}

void NutritionCalculator::visit(Cheese const* c) {
    double ratio = c->getWeight() / 100.0;
    totalCalories += c->getCaloriesPer100g() * ratio;
    totalProtein += c->getProteinPer100g() * ratio;
    totalFat += c->getFatPer100g() * ratio;
    totalCarbs += c->getCarbsPer100g() * ratio;
    totalCost += c->getCostPer100g() * ratio;
}

void NutritionCalculator::visit(DillAndSpices const* d) {
    double ratio = d->getWeight() / 100.0;
    totalCalories += d->getCaloriesPer100g() * ratio;
    totalProtein += d->getProteinPer100g() * ratio;
    totalFat += d->getFatPer100g() * ratio;
    totalCarbs += d->getCarbsPer100g() * ratio;
    totalCost += d->getCostPer100g() * ratio;
}