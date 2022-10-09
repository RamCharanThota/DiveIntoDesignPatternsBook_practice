#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class CarBase
{
    string name_;
    string color_;
    public:
    CarBase(string name ,string color)
    {
        name_=name;
        color_=color;
    }

    void setColor(string color){
        color_=color;
    }

    CarBase()=default;
};
class RaceCar:public CarBase{
   int max_speed_;
   public:
   RaceCar(string name,string color,int maxspeed){
    CarBase(std::move(name),std::move(color));
    max_speed_=maxspeed;
   }

    std::unique_ptr<CarBase> clone() const {
        return std::make_unique<RaceCar>(*this);
    }
};

int main()
{
 std::vector<std::unique_ptr<CarBase>> cars;
 const auto prototype =std::make_unique<RaceCar>("ferari","",300);
 auto redCar=prototype->clone();
 redCar->setColor("blue");

 auto blueCar=prototype->clone();
 blueCar->setColor("blue");


 cars.emplace_back(redCar);
 cars.emplace_back(blueCar);



}