// return- return a value back to the spot where you called the function
// return a value back
// *************************************************************************************************************************
// RETURN- kisi aur function mei calculate krke main function mei uski value as a datatype daalna
// idhar square function mei hum result as integer calculate kr rahe hain    FIR   us result ko hum main function mei area ke
// andar substitute kr rahe hai as an integer
// value return krna
// jo value calculate hui vo print ke bajaye code mei hi return ho rahi hai aur final output mil raha hai
// ************************************************************************************************************************

#include <iostream>

using namespace std;

double square(double length);
double cube(double length);
int main(){

    double length = 5.0;
    double area = square(length);
    double volume = cube(length);
    cout<<"Area of the square is: "<<area<< "cm^2"<< endl;
    cout<<"Volume of the square is: "<<volume<< "cm^3"<< endl;
    return 0;
}

double square(double length){ // we are returning a double so we change void into a double
    double result = length*length;
    return result;
    // or
    // return length*length

}
double cube(double length){
    return  length * length * length;
}


// ************************************************************************************************************************

// OR
// wihtout using reurn direct cout and void
// #include <iostream>

// using namespace std;

// void square(){


//     double length;
//     cout<< "Enter the length of the square:";
//     cin >> length;
//     double area  = length*length;
//     cout<<"Area of the square is:"<< area << "cm^2";
// }

// int main(){
//     square();
//     return 0;

// }
// ***********************************************************************************************************************
