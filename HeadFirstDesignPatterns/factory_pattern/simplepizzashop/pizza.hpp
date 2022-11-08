#ifndef PIZZA_HPP
#define PIZZA_HPP
#include <iostream>
#include <string>

class Pizza
{
protected:
  std::string name_ = "no string";

public:
  virtual void prepare()=0;
  virtual void brake()=0;
  virtual void cut()=0;
  virtual void box()=0;
};

class ChessePizza : public Pizza
{
public:
  ChessePizza()
  {
    name_ = "Cheesecake";
  }
  void prepare()
  {
    std::cout << "prepareing " << this->name_<<"\n";
  }

  void brake()
  {
    std::cout << "breaking " << this->name_<<"\n";
  }

  void cut()
  {
    std::cout << "cutting " << this->name_<<"\n";
  }
  void box()
  {
    std::cout << "boxing " << this->name_<<"\n";
  }
};

class PepperoniPizza : public Pizza
{
public:
  PepperoniPizza()
  {
    name_ = "PepperoniPizza";
  }
  void prepare()
  {
    std::cout << "prepareing " << this->name_<<"\n";
  }

  void brake()
  {
    std::cout << "breaking " << this->name_<<"\n";
  }

  void cut()
  {
    std::cout << "cutting " << this->name_<<"\n";
  }
  void box()
  {
    std::cout << "boxing " << this->name_<<"\n";
  }
};

class ClaimPizza : public Pizza
{
public:
  ClaimPizza()
  {
    name_ = "ClaimPizza";
  }
  void prepare()
  {
    std::cout << "prepareing " << this->name_<<"\n";
  }

  void brake()
  {
    std::cout << "breaking " << this->name_<<"\n";
  }

  void cut()
  {
    std::cout << "cutting " << this->name_<<"\n";
  }
  void box()
  {
    std::cout << "boxing " << this->name_<<"\n";
  }
};

class VeggiePizza : public Pizza
{
public:
  VeggiePizza()
  {
    name_ = "VeggiePizza";
  }
  void prepare()
  {
    std::cout << "prepareing " << this->name_<<"\n";
  }

  void brake()
  {
    std::cout << "breaking " << this->name_<<"\n";
  }

  void cut()
  {
    std::cout << "cutting " << this->name_<<"\n";
  }
  void box()
  {
    std::cout << "boxing " << this->name_<<"\n";
  }
};

#endif