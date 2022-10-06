#include <iostream>
#include<string>
 
 using namespace std;
struct Office{
    string street;
    string city;
    int32_t cubical;

    Office(string s,string c,int32_t n):street(s),city(c),cubical(n){}
};

struct Employee{
   string name;
   Office office;
   Employee (string n, Office o):name(n),office(o){}
};

int main(){
    Employee john{"John Doe",Office{"123 east","london",123}};

    Employee john{"John Doe",Office{"123 east","london",456}};

    return EXIT_SUCCESS;

}