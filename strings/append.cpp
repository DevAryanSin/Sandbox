#include <iostream>
#include <string>

using namespace std;
//name.append changes the input string
int main(){

string name;
cout<<"Enter your name: \n";
getline (cin , name);

name.append("@gmail.com");

cout << "Your email address is: " << name << endl;


    return 0;
}
