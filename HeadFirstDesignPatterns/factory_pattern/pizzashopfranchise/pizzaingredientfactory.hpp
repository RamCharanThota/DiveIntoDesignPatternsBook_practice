#ifndef PIZZAINGREDIENTFACTORY_HPP
#define PIZZAINGREDIENTFACTORY_HPP
#include "pizzaingredient.hpp"
#include<vector>
#include<memory>

class PizzaIngredientFactory{
    public:
    std::unique_ptr<Dough> createDough();
    std::unique_ptr<Sauce> createSauce();
    std::unique_ptr<Cheese> createCheese();
    std::vector<std::unique_ptr<Veggies>> createVeggies();
    std::unique_ptr<Pepperoni> createPepperoni();
    std::unique_ptr<Clams> createClams();
};

#endif