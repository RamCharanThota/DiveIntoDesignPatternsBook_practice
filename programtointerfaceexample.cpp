#include <iostream>

class Food{
    public:
      virtual int getNutrition()=0;

};

class Sausage: public Food{
    
    public:
       int getNutrition(){
        return 300;
       }
};

class Fruit: public Food{
    public:
     int getNutrition(){
        return 100;
       }
     
};

class Cat{

    int energy_=0;
     Food *f_;
    public:
    void eat( ){
       energy_=energy_+f_->getNutrition();
    }

    int currentEnergy(){
        return energy_;
    }

    void setFood(Food *f){
        f_=f;
    }

};

int main(){
    Sausage s;
    Fruit f;
    Cat c;
    c.setFood(&s);
    c.eat();
    std::cout<<"the current energy is :"<<c.currentEnergy()<<std::endl;

    c.setFood(&f);
    c.eat();
    std::cout<<"the current energy is :"<<c.currentEnergy()<<std::endl;


    
}