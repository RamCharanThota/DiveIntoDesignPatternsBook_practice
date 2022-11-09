#ifndef SIMPLEPIZZAFACTORY_HPP
#define SIMPLEPIZZAFACTORY_HPP
#include "pizza.hpp"
#include "string"
#include "memory"

class SimplePizzeFactory
{
public:
  std::unique_ptr<Pizza> createPizza(std::string type)
  {
    std::unique_ptr<Pizza> pza_ptr=nullptr;
  

    return std::move(pza_ptr);
  }
};

#endif