// a class design with out factory pattern
#include <iostream>

using namespace std;

//Librabry classed

class Vehicle{
    public:
    virtual void printVehicle()=0;
};

class TwoWheeler : public Vehicle{
    public:
      void printVehicle(){
        cout<<"I am a two wheeler"<<std::endl;
      }
};

class FourWheeler : public Vehicle{
    public:
      void printVehicle(){
        cout<<"I am a Four wheeler"<<std::endl;
      }
};

// Client (or user) class
class Client {
public:
    Client(int type)
    {
        if (type == 1)
            pVehicle = new TwoWheeler();
        else if (type == 2)
            pVehicle = new FourWheeler();
        else
            pVehicle = NULL;
    }
 
    ~Client()
    {
        if (pVehicle) {
            delete pVehicle;
            pVehicle = NULL;
        }
    }
 
    Vehicle* getVehicle() { return pVehicle; }
 
private:
    Vehicle* pVehicle;
};

int main(){
    Client c1(1);
    c1.getVehicle()->printVehicle();
}

// problem with above design is , when new vehicle type is added to librabry
// the clinet to create a new if else condition and it needs to be changed whenever there is a change in
// subclass of the libarayr.which is a bad practice and it can be solved by using factory pattern
 