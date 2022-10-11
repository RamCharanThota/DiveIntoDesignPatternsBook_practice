/* 
simple example of the bridge pattern */
#include<iostream>
class Device{
    public:
    virtual bool isEnabled()=0;
    virtual void enable()=0;
    virtual void disable()=0;
    virtual int getVolume()=0;
    virtual void setVolume(int vol)=0;
    

};

class Radio:public Device{
    int volume_=0;
    bool status_=false;
    public:
    bool isEnabled(){
      return status_;
    }
    void enable(){
        if(!status_){
            status_=true;
            std::cout<<"the radio is turned on :"<<std::endl;
        }
     
    }

    void disable(){
        if(status_){
            status_=false;
            std::cout<<"the radio is turned off :"<<std::endl;
        }
    
    }

    int getVolume(){
        return volume_;
    }

    void setVolume(int volume){
        volume_=volume;
        std::cout<<"the radio volume is set to :"<<volume_<<std::endl;
    }

};

class Tv:public Device{
    int volume_=0;
    bool status_=false;
    public:
    bool isEnabled(){
      return status_;
    }
    void enable(){
        if(!status_){
            status_=true;
            std::cout<<"the tv is turned on :"<<std::endl;
        }
    }

    void disable(){
        if(status_){
            status_=false;
            std::cout<<"the tv is turned off :"<<std::endl;
        }
    }

    int getVolume(){
        return volume_;
    }

    void setVolume(int volume){
        volume_=volume;
        std::cout<<"the tv volume is set to :"<<volume_<<std::endl;
    }

};

class RemoteControl{
    protected:
    Device* device_;
    public:
    RemoteControl(Device* device){
        this->device_=device;
    }
    void togglePower(){
        if(device_->isEnabled()){
            device_->disable();
        }else{
            device_->enable();
        }
    }

    void volumeDown(){
        device_->setVolume(device_->getVolume()-10);
    }

    void volumeUp(){
        device_->setVolume(device_->getVolume()+10);
    }

};

class AdvanacedRemoteControl:public RemoteControl{
    public:
    void mute(){
        device_->setVolume(0);
    }
};

/* client node */
int main(){
    Tv tv;
    RemoteControl remote(&tv);
    remote.togglePower();
    remote.togglePower();

}