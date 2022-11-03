#include <iostream>

using namespace std;
class Parent
{
protected:
  int age_ = 30;

public:
  Parent(int age)
  {
    age_ = age;
    cout<<"parent with age constructor"<<endl;

  }

  Parent(){
    age_=50;
    cout<<"parent with out constructor"<<endl;
  }
  int getAge()
  {
    return age_;
  }
};

class Child : public Parent
{

public:
  Child(int age)
  {
    age_=age;
    cout<<"child with age constructor"<<endl;
    
  }

  Child(){
    age_=20;
    cout<<"child with out age constructor"<<endl;
  }

  int getAge()
  {
    return age_;
  }
};

int main()
{
  Child c(20);
  cout<<"age is"<<c.getAge();
  Parent p;
cout<<"age is "<<p.getAge();
}