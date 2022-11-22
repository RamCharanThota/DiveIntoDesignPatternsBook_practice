#include<iostream>
#include<string>

using namespace std;

class Singleton{
    private:
    string name_;
   static Singleton* singleton_instance_;
    Singleton(){

    }
    public:
   static Singleton* createInstance(){
        if(singleton_instance_==nullptr){
            singleton_instance_= new Singleton();

        }
            return singleton_instance_;
    }
    void display(){
        std::cout<<"single is created : "<<name_<<"\n";
    }

    void setName(string name){
        name_=name;
    }

    ~Singleton(){
        delete singleton_instance_;
    }
};

Singleton* Singleton::singleton_instance_=nullptr;

int main(){
    Singleton* pattern=Singleton::createInstance();
   Singleton* pattern2 =Singleton::createInstance();
    pattern->setName("fist_instance");
    pattern->display();
    pattern2->display();


    
}