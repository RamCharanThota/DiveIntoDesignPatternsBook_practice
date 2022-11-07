#pragma once
#include <iostream>
#include <string>

using namespace std;
class Beverage
{


public:
enum Size
  {
    Tall,
    Grande,
    Venti
  };
  virtual string getDescription()
  {
    return description_;
  }

  virtual float cost() = 0;
  virtual void setSize(Size size) = 0;
  virtual Size getSize() = 0;

  protected:
  

  string description_ = "unknown beverage";
  Size size_;
};

class HouseBlend : public Beverage
{
  float cost_;

public:
  HouseBlend()
  {
    description_ = "HouseBlend";
  }
  float cost()
  {
    if (size_ == Tall)
    {
      return 0.8;
    }
    if (size_ == Grande)
    {
      return 0.9;
    }
    if (size_ == Venti)
    {
      return 1.4;
    }
  }
  void setSize(Size size)
  {
    size_ = size;
  }

  Size getSize()
  {
    return size_;
  }
};

class DarkRoast : public Beverage
{
  float cost_;

public:
  DarkRoast()
  {
    description_ = "DarkRoast";
  }
  float cost()
  {
    if (size_ == Tall)
    {
      return 0.8;
    }
    if (size_ == Grande)
    {
      return 0.9;
    }
    if (size_ == Venti)
    {
      return 1.4;
    }
  }

  void setSize(Size size)
  {
    size_ = size;
  }

  Size getSize()
  {
    return size_;
  }
};

class Espresso : public Beverage
{
  float cost_;

public:
  Espresso()
  {
    description_ = "Espressp";
  }
  float cost()
  {
    if (size_ == Tall)
    {
      return 0.8;
    }
    if (size_ == Grande)
    {
      return 0.9;
    }
    if (size_ == Venti)
    {
      return 1.4;
    }
  }

  void setSize(Size size)
  {
    size_ = size;
  }

  Size getSize()
  {
    return size_;
  }
};

class Decaf : public Beverage
{
  float cost_;

public:
  Decaf()
  {
    description_ = "Decaf";
  }
  float cost()
  {
    if (size_ == Tall)
    {
      return 0.8;
    }
    if (size_ == Grande)
    {
      return 0.9;
    }
    if (size_ == Venti)
    {
      return 1.4;
    }
  }
  void setSize(Size size)
  {
    size_ = size;
  }

  Size getSize()
  {
    return size_;
  }
};
