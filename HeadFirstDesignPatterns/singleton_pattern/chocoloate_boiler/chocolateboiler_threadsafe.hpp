#ifndef CHOCOLATEbOILER_HPP
#define CHOCOLATEbOILER_HPP

/* this implementation is thread safe */

#include <mutex>

class ChocolateBoiler
{
private:
    bool empty_, boiled_;
    volatile static ChocolateBoiler* chocolateboiler_instance_;
    static std::mutex chocolateboiler_instance_mtx; // protect uniqueInstance
    ChocolateBoiler()
    {
        empty_ = true;
        boiled_ = false;
    }

public:

  volatile static ChocolateBoiler* getChocBoilerInstance(){
        std::lock_guard<std::mutex> gaurd(chocolateboiler_instance_mtx); // lock
        if(chocolateboiler_instance_==nullptr){
            chocolateboiler_instance_= new ChocolateBoiler();
        }

        return chocolateboiler_instance_;
    }
    

    bool isEmpty()
    {
        return empty_;
    }

    bool isBoiled()
    {
        return boiled_;
    }

    void fill()
    {
        if (isEmpty())
        {
            empty_ = false;
            boiled_ = false;
        }
    }

    void drain()
    {
        if (!isEmpty() && isBoiled())
        {
            empty_ = true;
        }
    }

    void boil()
    {
        if (!isEmpty() && !isBoiled())
        {
            boiled_ = true;
        }
    }
    ~ChocolateBoiler(){
        delete chocolateboiler_instance_;
    }
};

 volatile ChocolateBoiler* ChocolateBoiler::chocolateboiler_instance_=nullptr;

#endif