#include"pizza.hpp"
#include"simplepizzafactory.hpp"
#include"pizzaStore.hpp"

int main(){
    std::unique_ptr<SimplePizzeFactory> pizza_factory_ptr= std::make_unique<SimplePizzeFactory>();
    auto pizzastore= PizzaStore(std::move(pizza_factory_ptr));
    auto pizza= pizzastore.orderPizza("veggie");
}