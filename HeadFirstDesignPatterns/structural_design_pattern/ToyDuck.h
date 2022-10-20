#pragma once

#include"Duck.h"

class ToyDuck:public Duck
{
  public:
  ToyDuck(){

  }

  void display() const{
    std::cout << "ToyDuck dick is displayed" << std::endl;
  }
};