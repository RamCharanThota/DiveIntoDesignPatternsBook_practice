#ifndef PIZZASTORE_HPP
#define PIZZASTORE_HPP

#include "simplepizzafactory.hpp"
#include "pizza.hpp"
#include <memory>

class PizzaStore
{
private:
  std::unique_ptr<SimplePizzeFactory> factory_ptr=nullptr;

public:
  PizzaStore(std::unique_ptr<SimplePizzeFactory> factory_ptr_)
  {
    factory_ptr_ = std::move(factory_ptr);
  }

  std::unique_ptr<Pizza>  orderPizza(std::string type)
  {
    std::unique_ptr<Pizza> pizza = factory_ptr->createPizza(type);
    pizza->prepare();
    pizza->brake();
    pizza->cut();
    pizza->box();

    return std::move(pizza);
  }
};

#endif