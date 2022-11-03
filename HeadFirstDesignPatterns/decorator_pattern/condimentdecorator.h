#pragma once
#include "beverage.h"
#include "memory"
class CondimentDecorator : public Beverage
{
protected:
  CondimentDecorator(std::unique_ptr<Beverage> beverage):beverage_(std::move(beverage)){};
  std::unique_ptr<Beverage> beverage_;
};

class Milk :public CondimentDecorator
{
public:
  Milk(std::unique_ptr<Beverage> beverage):CondimentDecorator(std::move(beverage))
  {
  }
  float cost()
  {
    return beverage_->cost()+0.2;
  }

  string getDescription()
  {
    return beverage_->getDescription()+",Milk";
  }
};

class Mocha :public CondimentDecorator
{

public:
 Mocha()=default;
  Mocha(std::unique_ptr<Beverage> beverage):CondimentDecorator(std::move(beverage)){
  }
  float cost()
  {
    return beverage_->cost()+0.5;
  }

  string getDescription()
  {
    return beverage_->getDescription()+",Mocha";
  }
};

class Soy : public CondimentDecorator
{

public:
  Soy(std::unique_ptr<Beverage> beverage):CondimentDecorator(std::move(beverage)){
  }
  float cost()
  {
    return beverage_->cost()+0.6;
  }

  string getDescription()
  {
    return beverage_->getDescription()+",Soy";
  }
};

class Whip :public CondimentDecorator
{
public:
  Whip(std::unique_ptr<Beverage> beverage):CondimentDecorator(std::move(beverage)){
  }
  float cost()
  {
    return beverage_->cost()+0.7;
  }

  string getDescription()
  {
    return beverage_->getDescription()+",Whip";
  }
};
