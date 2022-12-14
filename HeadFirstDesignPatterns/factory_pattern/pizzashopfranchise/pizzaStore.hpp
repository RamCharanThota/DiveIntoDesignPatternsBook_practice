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
  virtual ~PizzaStore()=default;

  std::unique_ptr<Pizza>  orderPizza(std::string type)
  {
    std::unique_ptr<Pizza> pizza = createPizza(type);
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();

    return std::move(pizza);
  }

  virtual std::unique_ptr<Pizza> createPizza(std::string type)=0;
};

class NYStylePizzaStore:public PizzaStore{
  public:

  std::unique_ptr<Pizza> createPizza(std::string type){
    std::unique_ptr<Pizza> pza_ptr=nullptr;
    std::unique_ptr<PizzaIngredientFactory> ingredientFactory =std::make_unique<NYPizzaIngredientFactory>();
    if (type.compare("cheese") == 0)
    {
      pza_ptr = std::make_unique<CheesePizza>(std::move(ingredientFactory));
    }else if (type.compare("claim") == 0)
    {
      pza_ptr = std::make_unique<ClamPizza>(std::move(ingredientFactory));
    }

    return std::move(pza_ptr);
  }
};

// class ChicagoStylePizzaStore:public PizzaStore{
//   public:
//   std::unique_ptr<Pizza> createPizza(std::string type){
//     std::unique_ptr<Pizza> pza_ptr=nullptr;
//     if (type.compare("cheese") == 0)
//     {
//       pza_ptr = std::make_unique<ChicagoCheesePizza>();
//     }else if (type.compare("Pepperoni") == 0)
//     {
//       pza_ptr = std::make_unique<ChicagoPepperoniPizza>();
//     }else if (type.compare("veggie") == 0)
//     {
//       pza_ptr = std::make_unique<ChicagoVeggiePizza>();
//     }else{
//         std::cout<<"pizza with required name is not avaiable"<<"\n";
//         return nullptr;
//     }

//     return std::move(pza_ptr);
//   }
// };

// class CaliforniaStylePizzaStore:public PizzaStore{
//   public:
//   std::unique_ptr<Pizza> createPizza(std::string type){
//     std::unique_ptr<Pizza> pza_ptr=nullptr;
//     if (type.compare("cheese") == 0)
//     {
//       pza_ptr = std::make_unique<CaliforniaCheesePizza>();
//     }else if (type.compare("Pepperoni") == 0)
//     {
//       pza_ptr = std::make_unique<CaliforniaPepperoniPizza>();
//     }else if (type.compare("veggie") == 0)
//     {
//       pza_ptr = std::make_unique<CaliforniaVeggiePizza>();
//     }else{
//         std::cout<<"pizza with required name is not avaiable"<<"\n";
//         return nullptr;
//     }

//     return std::move(pza_ptr);
//   }
// };

#endif