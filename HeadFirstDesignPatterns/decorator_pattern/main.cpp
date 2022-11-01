#include"condimentdecorator.h"

int main(){
   std::unique_ptr<Beverage> beverage1=std::make_unique<Espresso>();
   cout<<beverage1->getDescription()<<" $"<<beverage1->cost()<<"\n";

   std::unique_ptr<Beverage> beverage2=std::make_unique<DarkRoast>();
   beverage2=std::make_unique<Mocha>(std::move(beverage2));
   beverage2=std::make_unique<Mocha>(std::move(beverage2));
   beverage2=std::make_unique<Whip>(std::move(beverage2));

  cout<<beverage2->getDescription()<<" $"<<beverage2->cost()<<"\n";


}