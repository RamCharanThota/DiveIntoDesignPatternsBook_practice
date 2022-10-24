#pragma once
#include"observer.h"
#include<string>
#include<vector>
#include<memory>

using namespace std;


class Subject{
    
    public:
    virtual void registerObserver(unique_ptr<Observer> ob)=0;
    virtual void removeObserver(unique_ptr<Observer> ob)=0;
    virtual void notifyObserver()=0;
};

class WeatherData:public Subject{
    protected:
    vector<unique_ptr<Observer>> observers;
    float temperature_;
    float humidity_;
    float pressure_;

    public:
    void registerObserver(unique_ptr<Observer> ob){
        observers.push_back(move(ob));
    }

    void registerObserver(Observer* ob){
      // TODO: add remove observer here
    }

    void notifyObserver(){
        for(auto const & ob:observers){
            ob->update(temperature_,humidity_,pressure_);
        }
    }

    void MeasurementsChanged(){
        notifyObserver();
    }

    void setMeasurements(float temp,float humidity,float pressure ){
        temperature_=temp;
        humidity_=humidity;
        pressure_=pressure;
        MeasurementsChanged();
    }



};