#include <iostream>
#include <string>

using namespace std;

// Function Overloading
// Same function name but different parameters
//parameter alag function alag use hoga
// function overloading is a compile time polymorphism
//func name
//func name + parameter --> Func Signature

string topping1;
string topping2;


void bakePizza();
void bakePizza(string topping1);
void bakePizza(string topping1, string topping2);

int main(){

// cout<< "Enter Topping:" << endl;
// getline (cin , topping1);

// cout<<"Enter Topping: " << endl;
// getline (cin , topping2);

// bakePizza(topping1,topping2);
bakePizza("cheese" , "double");

return 0;

}


void bakePizza(){
    cout<< "Baking Pizza!!";
}

void bakePizza(string topping1){
    cout<< "Baking Pizza with "<< topping1 << '\n';
}

void bakePizza(string topping1, string topping2){
    cout<< "Baking Pizza with "<< topping1 << " and " << topping2 << '\n';
}

// NO input - Baking Pizza --> 1st Function
// 1 input - Baking Pizza with 1 topping --> 2nd Function
// 2 inputs - Baking Pizza with t1 and t2 --> 3rd Function
