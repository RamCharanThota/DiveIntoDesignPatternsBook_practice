#ifndef CHOCOLATEbOILER_HPP
#define CHOCOLATEbOILER_HPP

/* this implementation is not thread safe */

class ChocolateBoiler
{
private:
    bool empty_, boiled_;
    static ChocolateBoiler* chocolateboiler_instance_;
    ChocolateBoiler()
    {
        empty_ = true;
        boiled_ = false;
    }

public:
   static ChocolateBoiler* getChocBoilerInstance(){
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

 ChocolateBoiler* ChocolateBoiler::chocolateboiler_instance_=nullptr;

#endif