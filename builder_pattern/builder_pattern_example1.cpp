//question: Why builder desing pattern
// answer: Because i want to build an object and it is composed of complex
// objects step by step

#include <iostream>
#include <string>

using namespace std;

class Plane{
    string plane_;
    string body_;
    string engine_;

    public:
    Plane (string plane_type):plane_(plane_type){};
    void setEngine(string engine_type) {engine_=engine_type;}
    void setBody(string body_type){body_=body_type;}
    string getEngine(){return engine_;}
    string getBody(){return body_;}

    void show(){
        cout<< "plane type "<<plane_<< endl
            << "Body Type "<< body_<< endl;
    }

};

class PlaneBuilder{
    protected:
    Plane * plane_;
    public:
    virtual void getPartsDone()=0;
    virtual void buildBody()=0;
    virtual void buildEngine()=0;
    Plane* getPlane(){return plane_;};

    ~PlaneBuilder(){};
};

class JetBuilder:public PlaneBuilder{
      public:
      void getPartsDone(){plane_=new Plane("Jet Plane");}
      void buildEngine(){plane_->setEngine("Jet Engine");}
      void buildBody(){plane_->setBody("jet body");}
      ~JetBuilder(){};
};

class PropllerBuilder:public PlaneBuilder{
      public:
      void getPartsDone(){plane_=new Plane("Propller Plane");}
      void buildEngine(){plane_->setEngine("Propller Engine");}
      void buildBody(){plane_->setBody("Propller body");}
      ~PropllerBuilder(){};
};

class Director{
    PlaneBuilder* builder;
    public:
    Plane* createPlane(PlaneBuilder* builder){
        builder->getPartsDone();
        builder->buildBody();
        builder->buildEngine();
        return builder->getPlane();
    }

    ~Director(){
    }
};

int main(){
    Director dir;
    JetBuilder jb;
    PropllerBuilder pb;
    Plane* jet=dir.createPlane(&jb);
    Plane* pro=dir.createPlane(&pb);
    jet->show();
    pro->show();

    delete jet;
    delete pro;
}

