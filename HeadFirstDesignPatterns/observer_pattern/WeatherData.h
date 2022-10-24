#include"Subject.h"
#include"Observer.h"
#include <string>
#include <vector>


class WeatherData : public Subject
{
protected:
  vector<Observer*> observers;
  float temperature_;
  float humidity_;
  float pressure_;

public:
  void registerObserver(Observer* ob)
  {
    observers.push_back(ob);
  }

  void removeObserver(Observer* ob)
  {
    // TODO: add remove observer here
  }

  void notifyObserver()
  {
    for (auto const& ob : observers)
    {
      ob->update(temperature_, humidity_, pressure_);
    }
  }

  void MeasurementsChanged()
  {
    notifyObserver();
  }

  void setMeasurements(float temp, float humidity, float pressure)
  {
    temperature_ = temp;
    humidity_ = humidity;
    pressure_ = pressure;
    MeasurementsChanged();
  }
};