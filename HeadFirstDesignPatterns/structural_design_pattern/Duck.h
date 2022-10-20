#pragma once

/* duck class */
#include <iostream>
#include<memory>

#include"FlyBehaviour.h"
#include"QuackBehaviour.h"

class Duck
{
protected:
  std::unique_ptr<FlyBehaviour> flyBehaviour_ = nullptr;
  std::unique_ptr<QuackBehaviour> quackBehavior_ = nullptr;

public: 
  void performQuack()  const
  {
    quackBehavior_->quack();
  }

  void performFly () const
  {
    flyBehaviour_->fly();
  }

  virtual void display() const =0;

  void swim() const
  {
    std::cout << "All ducks float, even decoys !" << std::endl;
  }
  void setFlyBehavior(std::unique_ptr<FlyBehaviour> fb){
    flyBehaviour_=std::move(fb);
    
  }
  void setQuackBehavior(std::unique_ptr<QuackBehaviour> qb){
    quackBehavior_=std::move(qb);
    
  }
  Duck()=default;
  ~Duck()=default;

  
};