#ifndef GADGETS_HPP
#define GADGETS_HPP

#include<iostream>

class Light{
    public:
    void on(){
       std::cout<<"light is on"<<std::endl; }

    void off(){ std::cout<<"light is on"<<std::endl;}
};

class GarageDoor{
    public:
    void up(){
        std::cout<<"GarageDoor is going up"<<std::endl;
    }

    void down(){
      std::cout<<"GarageDoor is going down"<<std::endl;

    }

};



#endif
