#include <iostream>

using namespace std;


// Function Overloading
// Same function name but different parameters
//parameter alag function alag use hoga
// function overloading is a compile time polymorphism

void bakePizza();
void bakePizza(string topping1);
void bakePizza(string topping1, string topping2);

int main(){

    bakePizza("cheeeessweeeee", "paaanneeeeeeeeeerrrrr");

    return 0;

}


void bakePizza(){
    cout<< " Baking Pizza!!";
}

void bakePizza(string topping1){
    cout<< " Baking Pizza with "<< topping1 << '\n';
}

void bakePizza(string topping1, string topping2){
    cout<< " Baking Pizza with "<< topping1 << " and " << topping2 << '\n';
}
