#include <iostream>
#include <string>
using  namespace std;
// name.empty returens boolean value(true or false)
int main(){
    string name;

cout << "Please enter your name: ";
getline (cin, name);

if (name.empty()){

    cout << "Your didn't enter your name";
}

else {
    cout << "Hello " << name;
}

return 0;
}
