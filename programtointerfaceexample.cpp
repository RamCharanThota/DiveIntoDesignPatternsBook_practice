#include <iostream>



class Sausage{
    
    public:
       int getNutrition(){
        return 300;
       }
};

class Cat{
    int energy_=0;
    public:
    void eat(Sausage s){
       energy_+=s.getNutrition();
    }

    int currentEnergy(){
        return energy_;
    }

};

int main(){
    Sausage s;
    Cat c;
    c.eat(s);
    std::cout<<"the current energy of cat is "<<c.currentEnergy();
}