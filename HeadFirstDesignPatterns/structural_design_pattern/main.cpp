#include <iostream>
#include <memory>
#include "MallardDuck.h"
#include "ToyDuck.h"








int main(){
    std::unique_ptr<Duck> mallard=std::make_unique<MallardDuck>();
    mallard->performFly();
    mallard->performQuack();

    std::unique_ptr<Duck> toyduck=std::make_unique<ToyDuck>();
    toyduck->setFlyBehavior(std::make_unique<FlyNoWay>());
    toyduck->setQuackBehavior(std::make_unique<MuteQuack>());
    toyduck->performFly();
    toyduck->performQuack();
    toyduck->display();
}