#include<iostream>
#include<memory>

struct Son;
struct Daughter;

struct Mother{
    ~Mother(){
        std::cout<<"mother gone"<<std::endl;
    }

    void setSon(const std::shared_ptr<Son> s){
        mySon=s;
    }

    void setDaughter(const std::shared_ptr<Daughter> d){
         myDaughter=d;
    }

    std::shared_ptr<const Son> mySon;
    std::weak_ptr<const Daughter> myDaughter;
};

struct Son{
    ~Son(){
         std::cout<<"son gone"<<std::endl;
    }

    Son(std::shared_ptr<const Mother> m){
        mother=m;
    }

    std::shared_ptr<const Mother> mother;
};

struct Daughter{
    ~Daughter(){
         std::cout<<"daughter gone"<<std::endl;
    }

    Daughter(std::shared_ptr<const Mother> m){
        mother=m;
    }

    std::shared_ptr<const Mother> mother;
};

int main(){
     std::cout<<std::endl;
    {
    std::shared_ptr<Mother> mother=std::shared_ptr<Mother>(new Mother);
    std::shared_ptr<Son> son=std::shared_ptr<Son>(new Son(mother));
    std::shared_ptr<Daughter> daughter=std::shared_ptr<Daughter>(new Daughter(mother));

    mother->setDaughter(daughter);
    mother->setSon(son);
    }

    std::cout<<std::endl;




}
