#include<iostream>
#include<typeinfo>


class Base{

};

class Dervied:public Base{

};

int main(){
    Base b1;
    Dervied d1;

    Base*b=&b1;
    std::cout<<"the type info is "<<typeid(*b).name()<<" \n";
    b=&d1;
    std::cout<<"the type info is "<<typeid(d1).name()<<" \n";

}