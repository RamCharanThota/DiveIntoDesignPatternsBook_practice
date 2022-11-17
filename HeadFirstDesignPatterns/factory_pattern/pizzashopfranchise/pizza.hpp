#ifndef PIZZA_HPP
#define PIZZA_HPP
#include <iostream>
#include <string>
#include <vector>
#include<memory>


#include"pizzaingredientfactory.hpp"

class Pizza
{
protected:
  std::string name_;
  std::unique_ptr<Dough> dough_ptr=nullptr;
  std::unique_ptr<Sauce> sauce_ptr=nullptr;
  std::unique_ptr<Cheese> cheese_ptr=nullptr;
  std::vector<std::unique_ptr<Veggies> > veggies_ptr;
  std::unique_ptr<Pepperoni> pepperoni_ptr=nullptr;
  std::unique_ptr<Clams> claims_ptr=nullptr;
public:
  virtual void prepare()=0;
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

 void setName(std::string name){
  name_=name;
 }

 std::string getName(){
  return name_;

 }
};

class CheesePizza:public Pizza{
  std::unique_ptr<PizzaIngredientFactory> ingredient_factory_ptr_;

  public:
  CheesePizza(std::unique_ptr<PizzaIngredientFactory> ingredient_factory_ptr){
    ingredient_factory_ptr_=std::move(ingredient_factory_ptr);

  }
  void prepare(){
    std::cout<<"Prepareing the "<<name_<<"\n";
    dough_ptr=std::move(ingredient_factory_ptr_->createDough());
    sauce_ptr=std::move(ingredient_factory_ptr_->createSauce());
    cheese_ptr=std::move(ingredient_factory_ptr_->createCheese());

  }

};

class ClamPizza:public Pizza{
  std::unique_ptr<PizzaIngredientFactory> ingredient_factory_ptr_;

  public:
  ClamPizza(std::unique_ptr<PizzaIngredientFactory> ingredient_factory_ptr){
    ingredient_factory_ptr_=std::move(ingredient_factory_ptr);

  }
  void prepare(){
    std::cout<<"Prepareing the "<<name_<<"\n";
    dough_ptr=std::move(ingredient_factory_ptr_->createDough());
    sauce_ptr=std::move(ingredient_factory_ptr_->createSauce());
    cheese_ptr=std::move(ingredient_factory_ptr_->createCheese());

  }

};


#endif