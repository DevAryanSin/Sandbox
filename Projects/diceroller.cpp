#include <iostream>
#include <ctime>
using namespace std;
// srand() - random number generator
// psuedo random- not pure random(but close)
// time(0) - current time
// current calendar time as a seed
// seed - starting point for random number generator
// seed is the first number that the random number generator starts with
// rand()- to invoke a random number
// % - modulus - divide and output the remainder
// for random number between 1 and 6--- % 6 + 1
// this gives the format to find the numbers randomly between two numbers
// For three dice rolling
int main (){

    srand(time(NULL));

    int num1 = (rand() % 6) + 1; // dice 1
    int num2 = (rand() % 6) + 1; // dice 2
    int num3 = (rand() % 6) + 1; // dice 3

    cout << num1 << '\n';
    cout << num2 << '\n';
    cout << num3 << '\n';
    
    return 0;

}
