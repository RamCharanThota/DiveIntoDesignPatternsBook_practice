#include <iostream>
#include<string>
 
 using namespace std;
struct Office{
    string street;
    string city;
    int32_t cubical;

    Office(string s,string c,int32_t n):street(s),city(c),cubical(n){}
};

class Employee{
    string name;
    Office* office;
    Employee(string n,Office *o):name(n),office(o){}

    friend class EmployeeFactory;

    public:
    Employee(const Employee &rhs) : name{rhs.name}, office{new Office{*rhs.office}} { };

     Employee& operator=(const Employee &rhs) {
        if (this == &rhs) return *this;
        name = rhs.name;
        office = new Office{*rhs.office};
        return *this;
     }



}

int main(){
    Employee john{"John Doe",Office{"123 east","london",123}};

    Employee john{"John Doe",Office{"123 east","london",456}};

    return EXIT_SUCCESS;

}