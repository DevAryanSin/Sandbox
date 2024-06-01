#include <iostream>
#include <string>
using  namespace std;
// name.length() finds the number of characters in a string
int main(){
    string name;

cout << "Please enter your name: ";
getline (cin, name);

if (name.length() > 12){

    cout << "Your name can't be over 12 characters";
}

else {
    cout << "Welcome " << name;
}

return 0;
}
