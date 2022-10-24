#pragma once

#include "Subject.h"
#include "DisplayElement.h"
#include "Observer.h"

class ThirdPartyDisplay : public Observer, DisplayElement
{
  float temperature_=0;
  float humidity_=0;
  float pressure_=0;
  Subject* weather_data_=nullptr;

public:
  ThirdPartyDisplay()=default;
  ThirdPartyDisplay(Subject* weatherData)
  {
    weather_data_ = weatherData;
    weather_data_->registerObserver(this);
  }
  void update(float temp, float humidity, float pressure)
  {
    this->temperature_ = temp;
    this->humidity_ = humidity;
    display();
  }
  void display()
  {
    std::cout << "temperature :" << temperature_ << " humidity:" << humidity_ << std::endl;
  }
};