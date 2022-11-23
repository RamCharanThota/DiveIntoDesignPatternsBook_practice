#ifndef COMMAND_HPP
#define COMMAND_HPP

#include"gadgets.hpp"


class Command{
    public:
    virtual void execute()=0;
};



class LightOnCommand :public Command{
    Light light_;

    public:
     LightOnCommand(Light light){
        this->light_=light;
    }

    void execute (){
        light_.on();
    }



};

class GarageDoorOpenCommand :public Command{
    GarageDoor g_door_;
    public:

    GarageDoorOpenCommand(GarageDoor g_door){
        this->g_door_=g_door;
    }

     void execute (){
        g_door_.up();
    }



};




#endif