#include"pizza.hpp"
#include"simplepizzafactory.hpp"
#include"pizzaStore.hpp"

int main(){
    std::unique_ptr<PizzaStore> nypizzastr= std::make_unique<NYStylePizzaStore>();
    auto pizza=nypizzastr->createPizza("cheese");
    pizza->prepare();
    pizza->bake();
    
}