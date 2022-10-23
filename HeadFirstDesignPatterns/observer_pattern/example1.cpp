#include <iostream>
#include <memory>
#include<string>
#include<vector>
using namespace std;

class Observer{
    int id_=0;
    public:
     void update() const{
        cout<<"observer \t " <<id_<< " \t got updated\n";
     }

     Observer(int id){
       id_=id;
     }

     int getId(){
        return id_;
     }
};

class Subject{
    bool state_;
    vector<Observer> observer_list;

    public:
    void registerObserver(Observer b){
        observer_list.push_back(b);
    }

    void removeObserver(Observer b){
        vector<Observer>::iterator iter = observer_list.begin();
        for(iter; iter < observer_list.end(); iter++){
            if(iter->getId()==b.getId()){
                observer_list.erase(iter);
                break;
            }

        }
    }
    void notifyAll(){
        for(auto ob :observer_list){
            ob.update();
        }
    }

    void changeState(){
        notifyAll();
    }



    

};

int main(){
    Subject sub;
    for(int i=0;i<10;i++){
        Observer ob(i);
        sub.registerObserver(ob);
        
    }

    sub.changeState();
}