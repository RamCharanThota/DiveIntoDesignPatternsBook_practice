#include<iostream>
#include<memory>

class DrawStrategy{
    public:
    virtual void draw()=0;
};
class OpenglStrategyy:public DrawStrategy{
   public:
   void draw(){
    std::cout<<" drawing using OpenGLstrategy"<<std::endl;
   }

};
class TestStrategy:public DrawStrategy{
     public:
   void draw(){
    std::cout<<" drawing using Teststrategy"<<std::endl;
   }

};
class Circle{
    std::unique_ptr<DrawStrategy> draw_strategy_ptr_;
    public:
    void draw(){
        draw_strategy_ptr_->draw();
    }
    Circle(std::unique_ptr<DrawStrategy> ds_ptr){
        draw_strategy_ptr_=std::move(ds_ptr);
    }


};

int main(){
    Circle c1(std::make_unique<TestStrategy>());
    c1.draw();
}