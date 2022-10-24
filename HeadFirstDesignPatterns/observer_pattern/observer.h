# pragma once
#include"subject.h"
#include<iostream>

class Observer{
    public:
    virtual void update(float temp,float humidity,float pressure)=0;
};

class DisplayElement{
    public:
    virtual void display()=0;
};

class CurrentConditionDisplay:public Observer , DisplayElement{
    float temperature_;
    float humidity_;
    float pressure_;
    unique_ptr<Subject> weather_data_;
    public:
    CurrentConditionDisplay(unique_ptr<Subject> WeatherData){
        weather_data_=std::move(WeatherData);
        weather_data_->registerObserver(this);

    }
    void update(float temp,float humidity,float pressure ){
        this->temperature_=temp;
        this->humidity_=humidity;
        display();

    }
    void display(){
        std::cout<<"temperature :"<<temperature_<<" humidity:"<<humidity_<<std::endl;

    }

};

class ThirdPartyDisplay:public Observer , DisplayElement{
    public:
    void update(float temp,float humidity,float pressure){

    }
    void display(){
        
    }

};


class StaticDisplay:public Observer , DisplayElement{
    public:
    void update(float temp,float humidity,float pressure){

    }
    void display(){
        
    }

};

class ForecastDisplay:public Observer , DisplayElement{
    public:
    void update(float temp,float humidity,float pressure){

    }
    void display(){
        
    }

};