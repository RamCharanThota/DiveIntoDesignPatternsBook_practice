#include "WeatherData.h"
#include "CurrentConditionDisplay.h"
#include"StaticDisplay.h"
#include"ThirdPartyDisplay.h"
#include"ForecastDisplay.h"

int main(){
     auto weatherData=WeatherData();
    CurrentConditionDisplay currentDisplay(&weatherData);
    StaticDisplay staticDisplay(&weatherData);
    ThirdPartyDisplay ThirdPartyDisplay(&weatherData);
    

    weatherData.setMeasurements(80,65,30.4);


}