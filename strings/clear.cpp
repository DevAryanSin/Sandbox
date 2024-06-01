#include <iostream>
#include <string>
using  namespace std;
//name.clear() clears strings
int main(){
    string name;

cout << "Please enter your name: ";
getline (cin, name);

name.clear();

cout<< "Hello! " << name << "Welcome to our website.";

return 0;
}
