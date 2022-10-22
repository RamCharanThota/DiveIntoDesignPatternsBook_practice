#pragma once

#include<iostream>
#include<memory>

class QuackBehaviour
{
public:
  virtual void quack() = 0;
};
class Quack : public QuackBehaviour
{
public:
  void quack()
  {
    std::cout << " quack quack quack" << std::endl;
  }
};

class Squeak : public QuackBehaviour
{
  void quack()
  {
    std::cout << " squeak squeak" << std::endl;
  }
};

class MuteQuack : public QuackBehaviour
{
public:
  void quack()
  {
    std::cout << "cant speak" << std::endl;
  }
};
