#include<iostream>
#include<memory>
#include<utility>

struct MyInt{
  MyInt(int i):i_(i){}
  ~MyInt(){
    std::cout<<"good bye from"<<i_<<std::endl;
  }
  int i_;
};

int main(){
    std::cout<<std::endl;

    /* // ----possible erros
    MyInt* myint15 = new MyInt(15);
    // assign the same resources to two different unique pointers owners
    // when object goes out of scope, delete will be called twice
    // which can lead to undefined behaviour
    std::unique_ptr<MyInt> uniquePtr15(myint15);
    std::unique_ptr<MyInt> uniquePtr15_duplicate(myint15); */

    // create the resource on dynamic memory and assign the resource to 
    // unique pointer
    std::unique_ptr<MyInt> uniquePtr1(new MyInt(1998));
    std::cout<<"unique ptr.get()"<<uniquePtr1.get()<<std::endl;

    // you can only move or tranfor the resource to anothe r pointer
    std::unique_ptr<MyInt> uniquePtr2(std::move(uniquePtr1));
    
    // .get () returns a raw pointer to resource
    std::cout<<"unique ptr.get()"<<uniquePtr1.get()<<std::endl;
    std::cout<<"unique ptr.get()"<<uniquePtr2.get()<<std::endl;

    {
        // smart pointer life depends on the scope
    std::unique_ptr<MyInt> local(new MyInt(2003));
    }

   // .reset() deletes the old resource (1998) and assign new resource (2011 here)
    uniquePtr2.reset(new MyInt(2011));

    std::cout<<std::endl;
    // returnsa pointer to the resource and releases it.
    MyInt* MyInt = uniquePtr2.release();
    delete MyInt;



}