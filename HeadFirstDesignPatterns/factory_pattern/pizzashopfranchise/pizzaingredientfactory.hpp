#ifndef PIZZAINGREDIENTFACTORY_HPP
#define PIZZAINGREDIENTFACTORY_HPP
#include "pizzaingredient.hpp"
#include <vector>
#include <memory>

class PizzaIngredientFactory
{
public:
  virtual std::unique_ptr<Dough> createDough() = 0;
  virtual std::unique_ptr<Sauce> createSauce() = 0;
  virtual std::unique_ptr<Cheese> createCheese() = 0;
  virtual std::vector<std::unique_ptr<Veggies>> createVeggies() = 0;
  virtual std::unique_ptr<Pepperoni> createPepperoni() = 0;
  virtual std::unique_ptr<Clams> createClams() = 0;
};

class NYPizzaIngredientFactory : public PizzaIngredientFactory
{
public:
 NYPizzaIngredientFactory()=default;
  std::unique_ptr<Dough> createDough()
  {
    return std::make_unique<ThinCrustDough>();
  }

  std::unique_ptr<Sauce> createSauce()
  {
    return std::make_unique<MarinaraSauce>();
  }

  std::unique_ptr<Cheese> createCheese()
  {
    return std::make_unique<ReggianoCheese>();
  }

  std::vector<std::unique_ptr<Veggies>>  createVeggies()
  {
    std::vector<std::unique_ptr<Veggies>> veggies;
    veggies.push_back(std::move(std::make_unique<Garlic>()));
    veggies.push_back(std::move(std::make_unique<Onion>()));
    veggies.push_back(std::move(std::make_unique<Mushroom>()));
    veggies.push_back(std::move(std::make_unique<RedPepper>()));

    return std::move(veggies);
  }

  std::unique_ptr<Pepperoni> createPepperoni(){

    return std::make_unique<SlicedPepperoni>();
  }

  std::unique_ptr<Clams> createClams()
  {
    return std::make_unique<FreshClams>();
  }
  ~ NYPizzaIngredientFactory()=default;
};

#endif