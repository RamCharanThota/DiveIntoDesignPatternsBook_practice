#include<iostream>
#include<memory>
#include<random>
#include<string>
#include<typeinfo>

template<typename T>

class Deleter{
  public:
  void operator()(T*ptr){
    ++Deleter::count;
  }

  void getInfo(){
    std::string type_id{typeid(T).name()};
    size_t sz=Deleter::count*sizeof(T);
    std::cout<<"Deleted "<<Deleter::count<<" objects of type:"<<type_id<<std::endl;
    std::cout<<"Freed size in bytes "<<sz<<" . "<<std::endl;
    std::cout<<std::endl;
  }

  private:
  static int count;
};

template <typename T>
int Deleter<T>::count=0;

// using alias for Deleter<int>
typedef Deleter<int> IntDeleter;



int main(){
  std::cout<<std::endl;

  {
    std::shared_ptr<int> shared_ptr1(new int,IntDeleter());
    std::shared_ptr<int> shared_ptr2(new int,IntDeleter());
    /* get delter function will return the deleter */
    auto intDeleter=std::get_deleter<IntDeleter>(shared_ptr1);
    intDeleter->getInfo();
    shared_ptr2.reset();
    intDeleter->getInfo();


  }

}