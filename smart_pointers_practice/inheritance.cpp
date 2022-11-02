#include <iostream>

class Parent
{
protected:
  int age_ = 30;

public:
  Parent(int age)
  {
    age_ = age;
  }
  int getAge()
  {
    return age_;
  }
};

class Child : public Parent
{
  int age_ = 15;

public:
  Child(int age):Parent(age)
  {
    
  }

  int getAge()
  {
    return age_;
  }
};

int main()
{
  Child c(20);
}