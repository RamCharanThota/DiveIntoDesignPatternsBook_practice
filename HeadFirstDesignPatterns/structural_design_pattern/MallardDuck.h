#pragma once

#include"Duck.h"

class MallardDuck : public Duck
{
public:
  MallardDuck()
  {
    flyBehaviour_ =std::make_unique<FlyWithWings>();
    quackBehavior_=std::make_unique<Quack>();
  }

  void display() const {
    std::cout << "mallard dick is displayed" << std::endl;
  }
};