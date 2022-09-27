#include<iostream>
#include<vector>
#include<string>
class Employee{
    public:
       virtual void doWork()=0;

};

class Designer:public Employee{
    public:
     void doWork(){
        std::cout<<"designer designed the software"<<std::endl;
     }

};

class Programmer:public Employee{
    public:
     void doWork(){
        std::cout<<"Programmer programed the software"<<std::endl;
     }

};

class Tester:public Employee{
    public:
     void doWork(){
        std::cout<<"Tester Tested the software"<<std::endl;
     }

};

class Company{
       std::vector< Employee*> employee_list;
        Designer *d;
        Programmer *p;
        Tester *t;

     public:
      Company(){
        d = new Designer;
        employee_list.push_back(d);
        p=new Programmer;
        employee_list.push_back(p);
         t= new Tester;
        employee_list.push_back(t);

      }
      void createSoftware(){
        employee_list[0]->doWork();
        employee_list[1]->doWork();
        employee_list[2]->doWork();
      }

      ~Company(){
        delete d;
        delete p;
        delete t;
      }
};

int main(){
    Company c;
    c.createSoftware();
}