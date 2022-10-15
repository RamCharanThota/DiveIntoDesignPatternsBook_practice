#include<iostream>
#include<memory>
#include<utility>

struct MyInt{
  MyInt(int i):i_(i){
    std::cout<<" Hello:"<<i_<<std::endl;
  }
  ~MyInt(){
    std::cout<<"good bye from : "<<i_<<std::endl;
  }
  int i_;
};

int main(){
    std::cout<<std::endl;

    std::shared_ptr<MyInt> shar_ptr(new MyInt(1998));
   /* here memory is allocated twice
   1) memory of myint is allocated
   2) memory of coutner is allocated  but with std::make_shared () dunc these memory allocations 
   become one so it is way faster */ 
   std::cout<<"shared pointer . use count(): "<<shar_ptr.use_count()<<std::endl;

   {
   std::shared_ptr<MyInt> local_shr_ptr(shar_ptr);
   std::cout<<"local pointer . use count(): "<<local_shr_ptr.use_count()<<std::endl;
   }
   std::cout<<"shared pointer . use count(): "<<shar_ptr.use_count()<<std::endl;

   // share pointer using copy constructor
   std::shared_ptr<MyInt> globalsharptr =shar_ptr;
   std::cout<<"shareptr.usecount(): "<<shar_ptr.use_count()<<std::endl;

   globalsharptr.reset();
   std::cout<<"shareptr.usecount(): "<<shar_ptr.use_count()<<std::endl;

   //something interesting
   shar_ptr=std::shared_ptr<MyInt>(new MyInt(2011));
   std::cout<<std::endl;





}