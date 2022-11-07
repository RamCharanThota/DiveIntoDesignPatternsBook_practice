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
    size_=Tall;
  }
  float cost()
  {
    if(size_==Tall){
      return beverage_->cost()+0.5;
    }
    if(size_==Grande){
      return beverage_->cost()+0.8;
    }
    if(size_==Venti){
      return beverage_->cost()+0.9;
    }

    }
    

  string getDescription()
  {
    return beverage_->getDescription()+",Milk";
  }

  void setSize(Size size){
    size_=size;
  }

  Size getSize(){
   return size_;
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
    if(size_==Tall){
      return beverage_->cost()+0.3;
    }
    if(size_==Grande){
      return beverage_->cost()+0.6;
    }
    if(size_==Venti){
      return beverage_->cost()+0.9;
    }
  }

  string getDescription()
  {
    return beverage_->getDescription()+",Mocha";
  }
  void setSize(Size size){
    size_=size;
  }

  Size getSize(){
   return size_;
  }
};

class Soy : public CondimentDecorator
{

public:
  Soy(std::unique_ptr<Beverage> beverage):CondimentDecorator(std::move(beverage)){
  }
  float cost()
  {
    if(size_==Tall){
      return beverage_->cost()+0.8;
    }
    if(size_==Grande){
      return beverage_->cost()+0.9;
    }
    if(size_==Venti){
      return beverage_->cost()+1.4;
    }
  }

  string getDescription()
  {
    return beverage_->getDescription()+",Soy";
  }

  void setSize(Size size){
    size_=size;
  }

  Size getSize(){
   return size_;
  }
};

class Whip :public CondimentDecorator
{
public:
  Whip(std::unique_ptr<Beverage> beverage):CondimentDecorator(std::move(beverage)){
  }
  float cost()
  {
    if(size_==Tall){
      return beverage_->cost()+0.7;
    }
    if(size_==Grande){
      return beverage_->cost()+0.8;
    }
    if(size_==Venti){
      return beverage_->cost()+0.9;
    }
  }

  string getDescription()
  {
    return beverage_->getDescription()+",Whip";
  }

  void setSize(Size size){
    size_=size;
  }

  Size getSize(){
   return size_;
  }
};
