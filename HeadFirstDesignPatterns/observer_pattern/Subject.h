#pragma once

#include <memory>
#include "Observer.h"

using namespace std;

class Subject
{
public:
  virtual void registerObserver(Observer* ob) = 0;
  virtual void removeObserver(Observer* ob) = 0;
  virtual void notifyObserver() = 0;
};
