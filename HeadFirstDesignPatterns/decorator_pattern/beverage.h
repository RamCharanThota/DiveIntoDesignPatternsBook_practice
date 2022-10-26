#pragma once
#include <iostream>
#include <string>

using namespace std;
class Beverage
{
  string description_;

public:
  string getDescription()
  {
    return description_;
  }

  virtual int cost() = 0;
};

class HouseBlend : public Beverage
{
  int cost_;

public:
  int cost()
  {
    return cost_;
  }
};

class DarkRoast : public Beverage
{
  int cost_;

public:
  int cost()
  {
    return cost_;
  }
};

class Espresso : public Beverage
{
  int cost_;

public:
  int cost()
  {
    return cost_;
  }
};

class Decaf : public Beverage
{
  int cost_;

public:
  int cost()
  {
    return cost_;
  }
};

