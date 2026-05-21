#include "Recipe.hpp"
#include "Ingredients.hpp"
#include "NutritionCalculator.hpp"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Состав блюда:\n";
    cout << "- Шампиньоны: 500г\n";
    cout << "- Креветки: 100г\n";
    cout << "- Сметана: 30г\n";
    cout << "- Сыр: 20г\n";
    cout << "- Укроп и пряности: 30г\n\n";
    
    Recipe recipe;
    recipe.addIngredient(new Mushrooms());
    recipe.addIngredient(new Shrimps());
    recipe.addIngredient(new SourCream());
    recipe.addIngredient(new Cheese());
    recipe.addIngredient(new DillAndSpices());
    
    NutritionCalculator calculator;
    recipe.accept(&calculator);
    
    cout << "Результаты:\n";
    cout << "Калорийность блюда: " << calculator.totalCalories << " кКал\n";
    cout << "Количество белков: " << calculator.totalProtein << " г\n";
    cout << "Количество жиров: " << calculator.totalFat << " г\n";
    cout << "Количество углеводов: " << calculator.totalCarbs << " г\n";
    cout << "Стоимость блюда: " << calculator.totalCost << " руб\n";
    
    return 0;
}