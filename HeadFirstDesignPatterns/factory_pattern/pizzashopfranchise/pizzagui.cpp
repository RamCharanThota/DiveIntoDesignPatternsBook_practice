#include"pizza.hpp"
#include"simplepizzafactory.hpp"
#include"pizzaStore.hpp"

int main(){
    std::unique_ptr<PizzaStore> nypizzastr= std::make_unique<NYStylePizzaStore>();
    auto pizaa=nypizzastr->orderPizza("cheese");
    
}