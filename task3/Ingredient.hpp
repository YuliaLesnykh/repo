#ifndef INGREDIENT_HPP
#define INGREDIENT_HPP

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

struct Mushrooms;
struct Shrimps;
struct SourCream;
struct Cheese;
struct DillAndSpices;

struct IngredientVisitor {
    virtual ~IngredientVisitor() {}
    virtual void visit(Mushrooms const*) = 0;
    virtual void visit(Shrimps const*) = 0;
    virtual void visit(SourCream const*) = 0;
    virtual void visit(Cheese const*) = 0;
    virtual void visit(DillAndSpices const*) = 0;
};

#endif