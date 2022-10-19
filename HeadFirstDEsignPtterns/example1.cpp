#include <iostream>
#include <memory>
class FlyBehaviour
{
public:
  virtual void fly() = 0;
};
class QuackBehaviour
{
public:
  virtual void quack() = 0;
};

class FlyWithWings : public FlyBehaviour
{
  void fly()
  {
    std::cout << "fly with the wings" << std::endl;
  }
};

class FlyNoWay : public FlyBehaviour
{
public:
  void fly()
  {
    std::cout << "cann't fly" << std::endl;
  }
};

class Quack : public QuackBehaviour
{
public:
  void quack()
  {
    std::cout << " quack quack quack" << std::endl;
  }
};

class Squeak : public QuackBehaviour
{
  void quack()
  {
    std::cout << " squeak squeak" << std::endl;
  }
};

class MuteQuack : public QuackBehaviour
{
public:
  void quack()
  {
    std::cout << "cant speak" << std::endl;
  }
};

class Duck
{
protected:
  std::unique_ptr<FlyBehaviour> flyBehaviour_ = nullptr;
  std::unique_ptr<QuackBehaviour> quackBehavior_ = nullptr;

public: 
  void performQuack()  const
  {
    quackBehavior_->quack();
  }

  void performFly () const
  {
    flyBehaviour_->fly();
  }

  virtual void display() const =0;

  void swim() const
  {
    std::cout << "All ducks float, even decoys !" << std::endl;
  }
   Duck()=default;
  ~Duck()=default;
};

class MallardDuck : public Duck
{
public:
  MallardDuck()
  {
    flyBehaviour_ =std::make_unique<FlyWithWings>();
    quackBehavior_=std::make_unique<Quack>();
  }

  void display() const {
    std::cout << "mallard dick is displayed" << std::endl;
  }
};

int main(){
    std::unique_ptr<Duck> mallard=std::make_unique<MallardDuck>();
    mallard->performFly();
    mallard->performQuack();
}