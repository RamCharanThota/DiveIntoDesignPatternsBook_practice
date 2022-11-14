#include<iostream>

class Singleton
{
    public:
    Singleton (const Singleton& s)=delete;
    static Singleton& get(){
        return s_instance;
    }

    void func(){
        std::cout<<"print"<<std::endl;
    }

    private:
      Singleton(){

      }

      static Singleton s_instance;

};
Singleton Singleton::s_instance;

int main(){
    Singleton::get().func();
}