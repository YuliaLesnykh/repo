#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct IngredientVisitor;

struct Ingredient {
    virtual ~Ingredient() {}
    virtual double getWeight() const = 0;
    virtual double getCaloriesPer100g() const = 0;
    virtual double getProteinPer100g() const = 0;
    virtual double getFatPer100g() const = 0;
    virtual double getCarbsPer100g() const = 0;
    virtual double getCostPer100g() const = 0;
    virtual void accept(IngredientVisitor* visitor) const = 0;
};

struct Mushrooms : Ingredient {
    double getWeight() const override { return 500.0; }
    double getCaloriesPer100g() const override { return 27.0; }
    double getProteinPer100g() const override { return 4.4; }
    double getFatPer100g() const override { return 1.0; }
    double getCarbsPer100g() const override { return 0.2; }
    double getCostPer100g() const override { return 20.0; }
    void accept(IngredientVisitor* visitor) const override;
};

struct Shrimps : Ingredient {
    double getWeight() const override { return 100.0; }
    double getCaloriesPer100g() const override { return 83.0; }
    double getProteinPer100g() const override { return 18.0; }
    double getFatPer100g() const override { return 1.0; }
    double getCarbsPer100g() const override { return 0.0; }
    double getCostPer100g() const override { return 50.0; }
    void accept(IngredientVisitor* visitor) const override;
};

struct SourCream : Ingredient {
    double getWeight() const override { return 30.0; }
    double getCaloriesPer100g() const override { return 120.0; }
    double getProteinPer100g() const override { return 3.3; }
    double getFatPer100g() const override { return 10.0; }
    double getCarbsPer100g() const override { return 3.3; }
    double getCostPer100g() const override { return 14.4; }
    void accept(IngredientVisitor* visitor) const override;
};

struct Cheese : Ingredient {
    double getWeight() const override { return 20.0; }
    double getCaloriesPer100g() const override { return 345.0; }
    double getProteinPer100g() const override { return 25.0; }
    double getFatPer100g() const override { return 25.0; }
    double getCarbsPer100g() const override { return 0.0; }
    double getCostPer100g() const override { return 70.0; }
    void accept(IngredientVisitor* visitor) const override;
};

struct DillAndSpices : Ingredient {
    double getWeight() const override { return 30.0; }
    double getCaloriesPer100g() const override { return 37.0; }
    double getProteinPer100g() const override { return 3.3; }
    double getFatPer100g() const override { return 0.0; }
    double getCarbsPer100g() const override { return 7.0; }
    double getCostPer100g() const override { return 20.0; }
    void accept(IngredientVisitor* visitor) const override;
};

struct Recipe {
    void addIngredient(Ingredient const* ing) {
        ingredients.push_back(ing);
    }

    void accept(IngredientVisitor* visitor) const {
        for (auto ing : ingredients) {
            ing->accept(visitor);
        }
    }

    ~Recipe() {
        for (auto ing : ingredients) {
            delete ing;
        }
    }

private:
    vector<Ingredient const*> ingredients;
};

struct IngredientVisitor {
    virtual ~IngredientVisitor() {}
    virtual void visit(Mushrooms const*) = 0;
    virtual void visit(Shrimps const*) = 0;
    virtual void visit(SourCream const*) = 0;
    virtual void visit(Cheese const*) = 0;
    virtual void visit(DillAndSpices const*) = 0;
};

void Mushrooms::accept(IngredientVisitor* visitor) const { visitor->visit(this); }
void Shrimps::accept(IngredientVisitor* visitor) const { visitor->visit(this); }
void SourCream::accept(IngredientVisitor* visitor) const { visitor->visit(this); }
void Cheese::accept(IngredientVisitor* visitor) const { visitor->visit(this); }
void DillAndSpices::accept(IngredientVisitor* visitor) const { visitor->visit(this); }

struct NutritionCalculator : IngredientVisitor {
    double totalCalories = 0;
    double totalProtein = 0;
    double totalFat = 0;
    double totalCarbs = 0;
    double totalCost = 0;

    void visit(Mushrooms const* m) override {
        double ratio = m->getWeight() / 100.0;
        totalCalories += m->getCaloriesPer100g() * ratio;
        totalProtein += m->getProteinPer100g() * ratio;
        totalFat += m->getFatPer100g() * ratio;
        totalCarbs += m->getCarbsPer100g() * ratio;
        totalCost += m->getCostPer100g() * ratio;
    }

    void visit(Shrimps const* s) override {
        double ratio = s->getWeight() / 100.0;
        totalCalories += s->getCaloriesPer100g() * ratio;
        totalProtein += s->getProteinPer100g() * ratio;
        totalFat += s->getFatPer100g() * ratio;
        totalCarbs += s->getCarbsPer100g() * ratio;
        totalCost += s->getCostPer100g() * ratio;
    }

    void visit(SourCream const* sc) override {
        double ratio = sc->getWeight() / 100.0;
        totalCalories += sc->getCaloriesPer100g() * ratio;
        totalProtein += sc->getProteinPer100g() * ratio;
        totalFat += sc->getFatPer100g() * ratio;
        totalCarbs += sc->getCarbsPer100g() * ratio;
        totalCost += sc->getCostPer100g() * ratio;
    }

    void visit(Cheese const* c) override {
        double ratio = c->getWeight() / 100.0;
        totalCalories += c->getCaloriesPer100g() * ratio;
        totalProtein += c->getProteinPer100g() * ratio;
        totalFat += c->getFatPer100g() * ratio;
        totalCarbs += c->getCarbsPer100g() * ratio;
        totalCost += c->getCostPer100g() * ratio;
    }

    void visit(DillAndSpices const* d) override {
        double ratio = d->getWeight() / 100.0;
        totalCalories += d->getCaloriesPer100g() * ratio;
        totalProtein += d->getProteinPer100g() * ratio;
        totalFat += d->getFatPer100g() * ratio;
        totalCarbs += d->getCarbsPer100g() * ratio;
        totalCost += d->getCostPer100g() * ratio;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Вариант 7: Рецепт блюда\n";
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

    cout << "Результаты подсчёта:\n";
    cout << "1. Калорийность блюда: " << calculator.totalCalories << " кКал\n";
    cout << "2. Количество белков: " << calculator.totalProtein << " г\n";
    cout << "3. Количество жиров: " << calculator.totalFat << " г\n";
    cout << "4. Количество углеводов: " << calculator.totalCarbs << " г\n";
    cout << "5. Стоимость блюда: " << calculator.totalCost << " руб\n";

    return 0;
}