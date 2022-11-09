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

class NYChessePizza : public Pizza
{
public:
  NYChessePizza()
  {
    name_ = "NYChessePizza";
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

class  NYPepperoniPizza : public Pizza
{
public:
  NYPepperoniPizza()
  {
    name_ = "NYPepperoniPizza";
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

class NYClaimPizza : public Pizza
{
public:
  NYClaimPizza()
  {
    name_ = "NYClaimPizza";
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

class NYVeggiePizza : public Pizza
{
public:
  NYVeggiePizza()
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

class ChicagoChessePizza : public Pizza
{
public:
  ChicagoChessePizza()
  {
    name_ = "ChicagoChesse Pizza";
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

class ChicagoPepperoniPizza : public Pizza
{
public:
  ChicagoPepperoniPizza()
  {
    name_ = "ChicagoPepperoniPizza";
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

class ChicagoClaimPizza : public Pizza
{
public:
  ChicagoClaimPizza()
  {
    name_ = "ChicagoClaimPizza";
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

class ChicagoVeggiePizza : public Pizza
{
public:
  ChicagoVeggiePizza()
  {
    name_ = "ChicagoVeggiePizza";
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