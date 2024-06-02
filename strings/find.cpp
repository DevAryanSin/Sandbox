#include <iostream>
#include <string>

using namespace std;
//name.find('') finds the first desired characters{case sensitive}
int main(){

string name;

cout<<"Enter your name: \n";
getline (cin , name);


cout << name.find('a');

    return 0;
}
