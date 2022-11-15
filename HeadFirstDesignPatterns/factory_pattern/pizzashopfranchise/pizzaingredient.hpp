#ifndef PIZZAINGREDIENT_HPP
#define PIZZAINGREDIENT_HPP

#include <string>

class Dough
{
protected:
  std::string name_;

public:
  virtual std::string getName()=0;
};

class ThinCrustDough : Dough
{
    public:
    ThinCrustDough(){
        name_="ThinCrustDough";
    }

    std::string getName(){
        return name_;
    }
};


class Sauce
{
protected:
  std::string name_;

public:
  virtual std::string getName()=0;
};

class MarinaraSauce : Sauce
{
    public:
    MarinaraSauce(){
        name_="MarinaraSauce";
    }

    std::string getName(){
        return name_;
    }
};

class Cheese
{
protected:
  std::string name_;

public:
  virtual std::string getName()=0;
};

class ReggianoCheese : Cheese
{
    public:
    ReggianoCheese(std::string name){
        name_="ReggianoCheese";
    }

    std::string getName(){
        return name_;
    }
};

class Veggies
{
protected:
  std::string name_;

public:
  virtual std::string getName()=0;
};

class Garlic : Veggies
{
    public:
    Garlic(){
        name_="Garlic";
    }

    std::string getName(){
        return name_;
    }
};

class Onion : Veggies
{
    public:
    Onion(){
        name_="Onion";
    }

    std::string getName(){
        return name_;
    }
};

class Mushroom : Veggies
{
    public:
    Mushroom(){
        name_="Mushroom";
    }

    std::string getName(){
        return name_;
    }
};

class RedPepper:public Veggies{
    public:
    RedPepper(){
        name_="RedPepper";
    }

    std::string getName(){
        return name_;
    }

};

class Pepperoni
{
protected:
  std::string name_;

public:
  virtual std::string getName()=0;
};

class SlicedPepperoni : Sauce
{
    public:
    SlicedPepperoni(){
        name_="SlicedPepperoni";
    }

    std::string getName(){
        return name_;
    }
};

class Clams
{
protected:
  std::string name_;

public:
  virtual std::string getName()=0;
};

class FreshClams : Clams
{
    public:
    FreshClams(){
        name_="FreshClams";
    }

    std::string getName(){
        return name_;
    }
};


#endif