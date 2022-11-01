#pragma once
#include <iostream>
#include <string>

using namespace std;
class Beverage
{
protected:
  string description_ = "unknown beverage";

public:
  string getDescription()
  {
    return description_;
  }

  virtual float cost() = 0;
};

class HouseBlend : public Beverage
{
  float cost_;

public:
  HouseBlend()
  {
    description_ = "HouseBlend";
    cost_ = 0.89;
  }
  float cost()
  {
    return cost_;
  }
};

class DarkRoast : public Beverage
{
  float cost_;

public:
  DarkRoast()
  {
    description_ = "DarkRoast";
    cost_ = 1.5;
  }
  float cost()
  {
    return cost_;
  }
};

class Espresso : public Beverage
{
  float cost_;

public:
  Espresso()
  {
    description_ = "Espressp";
    cost_ = 1.99;
  }
  float cost()
  {
    return cost_;
  }
};

class Decaf : public Beverage
{
  float cost_;

public:
  Decaf()
  {
    description_ = "Decaf";
    cost_ = 1.89;
  }
  float cost()
  {
    return cost_;
  }
};
