#include<iostream>

class Base{
    public:
    Base(){std::cout<<" Base Constructor  called\n";}
    //~Base(){std::cout<<" Base Destructor  called\n";}
    virtual ~Base(){std::cout<<" Base Destructor  called\n";}



};

class Derived:public Base{
    public:
    Derived(){std::cout<<" Derived Constructor  called\n";}
    ~Derived(){std::cout<<" Derived Destructor  called\n";}


};

int main(){
    //scenario one
    Base*base =new Base();
    delete base;
    std::cout<<"-------------------------------\n";
    Derived*derived =new Derived();
    delete derived;
    /* in this following scenarios, only base destructor will be called
       no the derived destructor which can lead to resource leak
       if the derived class as resposnsibility of some resource
       - virtual destructor of base class whii make sure all the derived class
        destructor called first before calling base desctructor.
     */
    std::cout<<"-------------------------------\n";
    Base*base_der =new Derived();
    delete base_der;

}