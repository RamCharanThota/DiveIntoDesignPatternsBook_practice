#ifndef PIZZA_HPP
#define PIZZA_HPP
#include <iostream>
#include <string>
#include <vector>

class Pizza
{
protected:
  std::string name;
  std::string dough;
  std::string sauce;
  std::vector<std::string> toppings;

public:
 virtual void prepare()
  {
    std::cout << "Preparing " << name << "\n";
    std::cout << "Tossing  " << dough << "\n";
    std::cout << "Adding  " << sauce << "\n";
    for (std::string topping : toppings)
    {
      std::cout << "Topping " << topping << "\n";
    }
  }
 virtual void bake()
  {
    std::cout << "Bake for 25 minutes at 350"
              << "\n";
  }

 virtual void cut()
  {
    std::cout << "Cutting the Pizza into diagonal slices"
              << "\n";
  }

  virtual void box()
  {
    std::cout << "Place pizza in official PizzaStore box"
              << "\n";
  }

  virtual std::string getName()
  {
    return name;
  }
};

class NYStyleCheesePizza : public Pizza
{
public:
  NYStyleCheesePizza()
  {
    name = "NY Style Sauce and Chesse Pizza";
    dough = "Thin Crust Dough";
    sauce = "Marinara Sauce";
    toppings.push_back("Shredded Mozzarealla Cheese");
  }
};
class NYPepperoniPizza:public Pizza{
  public:
  NYPepperoniPizza(){
    name = "NY Style Pepperoni Pizza";
    dough = "Thin Crust Dough";
    sauce = "Marinara Sauce";
    toppings.push_back("Shredded Mozzarealla Cheese");

  }

};

class NYVeggiePizza:public Pizza{
  public:
  NYVeggiePizza(){
    name = "NY Style Veggie Pizza";
    dough = "Thin Crust Dough";
    sauce = "Marinara Sauce";
    toppings.push_back("Shredded Mozzarealla Cheese");

  }

};

class ChicagoCheesePizza : public Pizza
{
public:
  ChicagoCheesePizza()
  {
    name = "Chicago Style Deep Dish Chesse Pizza";
    dough = "Extra Thick Crust Dough";
    sauce = "Plum Tomato Sauce";
    toppings.push_back("Grated Reggiano Cheese");
  }
  void cut(){
    std::cout<<"Cutting the Pizza into Square Slices"<<"\n";
  }
};
class ChicagoPepperoniPizza:public Pizza{
  public:
  ChicagoPepperoniPizza(){
   name = "Chicago Style Pepperoni Pizza";
    dough = "Extra Thick Crust Dough";
    sauce = "Plum Tomato Sauce";
    toppings.push_back("Grated Reggiano Cheese");

  }

};

class ChicagoVeggiePizza:public Pizza{
  public:
  ChicagoVeggiePizza(){
    name = "Chicago Style Veggie Pizza";
    dough = "Thin Crust Dough";
    sauce = "Marinara Sauce";
    toppings.push_back("Shredded Mozzarealla Cheese");

  }

};

#endif