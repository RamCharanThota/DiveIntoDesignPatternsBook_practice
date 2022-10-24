#include<iostream>

class Base{
    public:
    Base(){std::cout<<" Base Constructor  called\n";}
    virtual ~Base(){std::cout<<" Base Destructor  called\n";}
    
    virtual void virtualFunc1(){
        std::cout<<"base virtualFunc1 called \n";
    }


    virtual void virtualFunc2(){
        std::cout<<"base virtualFunc2 called \n";
    }

    virtual void func1(){
        std::cout<<"base func1 called \n";
    }
    virtual  void func2(){
        std::cout<<"base func2 called \n";
    }

    //virtual void  pureVirtualFunc()=0;



};

class Derived:public Base{
    public:
    Derived(){std::cout<<" Derived Constructor  called\n";}
    ~Derived(){std::cout<<" Derived Destructor  called\n";}
     void virtualFunc1(){
        std::cout<<"Derived virtualFunc1 called \n";
    }

    void func1(){
        std::cout<<"Derived func1 called \n";
    }


};

int main(){
    //scenario one
    Base*base =new Base();
    base->func1();
    base->func2();
    base->virtualFunc1();
    base->virtualFunc2();
    std::cout<<"-------------------------------\n";
    std::cout<<std::endl;

    base=new Derived();
    base->func1();
    base->func2();
    base->virtualFunc1();
    base->virtualFunc2();


    delete base;
    
   // Base*base =new Derived();




   
    
   
}
