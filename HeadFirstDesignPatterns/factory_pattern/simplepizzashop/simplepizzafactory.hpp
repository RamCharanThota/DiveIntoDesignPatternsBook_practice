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
    if (type.compare("cheese") == 0)
    {
      pza_ptr = std::make_unique<ChessePizza>();
    }else if (type.compare("Pepperoni") == 0)
    {
      pza_ptr = std::make_unique<PepperoniPizza>();
    }else if (type.compare("veggie") == 0)
    {
      pza_ptr = std::make_unique<VeggiePizza>();
    }else{
        std::cout<<"pizza with required name is not avaiable"<<"\n";
    }

    return std::move(pza_ptr);
  }
};

#endif