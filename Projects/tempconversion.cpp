#include <iostream>

using namespace std;
// Converting units of temperature
int main(){

double temp ;
char unit ;

cout<< "***** Temperature Conversion *****\n" ;
cout<< "F = Farenheit\n";
cout<< "C = Celsius\n";
cout<< "What unit you would like to convert to?\n";
cin >> unit ;

if (unit == 'F' || unit == 'f'){
    cout<< "Enter the temperature in Celsius:\n";
    cin >> temp;

    temp = ( 9/5 * temp )  + 32.0;
    cout << "The Temperature in Farenheit is: " << temp << "F";
}

else if (unit == 'C' || unit == 'c'){
    cout<< "Enter the temperature in Farenheit; \n";
    cin >> temp;
    
    temp = (temp - 32)/1.8;
    cout << "The temperature is: " << temp << "C\n";
    
}

else {
    cout << "Please enter temperature in C/F only";
}


cout << "*******************************************";

return 0;
}
