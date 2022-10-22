#pragma once

#include <iostream>
#include <memory>

class FlyBehaviour
{
public:
  virtual void fly() = 0;
};


class FlyWithWings : public FlyBehaviour
{
  void fly()
  {
    std::cout << "fly with the wings" << std::endl;
  }
};

class FlyNoWay : public FlyBehaviour
{
public:
  void fly()
  {
    std::cout << "cann't fly" << std::endl;
  }
};

