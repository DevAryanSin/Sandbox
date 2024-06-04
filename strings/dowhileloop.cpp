#include <iostream>
#include <string>
using namespace std;
// Do while loop- It loops when the conditions is true
// do some block of code first, THEN repeat again if condition is true/


int main()
{
int number;

   
 do{
    cout<<"Enter a positive number: ";
    cin >> number;

    }while (number < 0);


    cout << "The positive number is: " << number;

}
