#ifndef SIMPLEREMOTE_HPP
#define SIMPLEREMOTE_HPP

#include"command.hpp"

class SimpleRemoteControl{
    Command* slot;

    public:
    SimpleRemoteControl(){}

    void setCommand(Command* command){
        slot=command;
    }

     void buttonWasPressed(){
        slot->execute();

    }


};




#endif