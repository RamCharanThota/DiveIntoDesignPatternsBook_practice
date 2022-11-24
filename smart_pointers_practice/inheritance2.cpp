#include<iostream>
using namespace std;


class Base{
   public:
   virtual void func1() {
      cout<<"base func 1 is called"<<"\n";
   }

   void func2(){
      cout<<"base func 2 is called"<<"\n";
   }
   
};

class Dervied:public Base{
   public:
   void func1() {
      cout<<"dervied func 1 is called"<<"\n";
   }
   void func3(){
      cout<<"derived func 3 is called"<<"\n";
   }

   void func4(){
      cout<<"dervied func 4 is called"<<"\n";
   }
   
};

int main(){
    Base *b;
    Dervied d;
    b=&d;
    b->func1();
    b->func2();
    d.func1();
}
 
