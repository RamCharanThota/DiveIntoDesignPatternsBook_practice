#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Subsystem1
{
public:
  string Operation1() const
  {
    return "subsytems1: is ready\n";
  }

  string Operation2() const
  {
    return "subsytems2: is ready\n";
  }

  string Operation3() const
  {
    return "subsytems3: is ready\n";
  }
};

class Subsystem2
{
public:
  string Operation1() const
  {
    return "subsytems1: is ready\n";
  }

  string Operation2() const
  {
    return "subsytems2: is ready\n";
  }

  string Operation3() const
  {
    return "subsytems3: is ready\n";
  }
};

class Facade
{
protected:
  Subsystem1* subsystem1_;
  Subsystem2* subsystem2_;

public:
  Facade(Subsystem1* subsystem1 = nullptr, Subsystem2* subsystem2 = nullptr)
  {
    this->subsystem1_ = subsystem1 ?: new Subsystem1;
    this->subsystem2_ = subsystem2 ?: new Subsystem2;
  }

  ~Facade()
  {
    delete subsystem1_;
    delete subsystem2_;
  }

  std::string Operation()
  {
    std::string result = "Facade initializes subsystems:\n";
    result += this->subsystem1_->Operation1();
    result += this->subsystem2_->Operation1();
    result += "Facade orders subsystems to perform the action:\n";
    result += this->subsystem1_->Operation2();
    result += this->subsystem2_->Operation3();
    return result;
  }
};

void ClientCode(shared_ptr<Facade> facade) {
  // ...
  std::cout << facade->Operation();
  // ...
}

int main(){
 Subsystem1 * subsystem1 =new Subsystem1;
 Subsystem2 * subsystem2 =new Subsystem2;

 shared_ptr<Facade> facade_ptr=make_shared<Facade>(subsystem1,subsystem2);

 ClientCode(facade_ptr);

 //delete facade;

 return 0;


}