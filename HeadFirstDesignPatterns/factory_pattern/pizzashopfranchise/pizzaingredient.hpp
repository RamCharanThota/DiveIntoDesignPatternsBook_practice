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

class ThinCrustDough :public Dough
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

class MarinaraSauce :public Sauce
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

class ReggianoCheese : public Cheese
{
    public:
    ReggianoCheese(){
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

class Garlic :public Veggies
{
    public:
    Garlic(){
        name_="Garlic";
    }

    std::string getName(){
        return name_;
    }
};

class Onion :public Veggies
{
    public:
    Onion(){
        name_="Onion";
    }

    std::string getName(){
        return name_;
    }
};

class Mushroom :public Veggies
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

class SlicedPepperoni :public Pepperoni
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

class FreshClams :public Clams
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