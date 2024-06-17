#include <iostream>
using namespace std;

string concatString(string string1, string string2); // function define


int main(){
 
    string firstName = "Aryan";
    string lastName = "Singh";
    string fullName = concatString(firstName, lastName); // references to string1 and string2
    
    cout<< "Your full name is: "<< fullName << endl;
    return 0;
}

string concatString(string string1, string string2){ // function declare
    return string1 + " " + string2;
}

// or
// string fullName = firstname + " " + lastName;
// cout << fullName;
