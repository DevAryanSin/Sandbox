#include <iostream>
#include <string>

using namespace std;
//name.at() gives character at a position in a string 0 se start
int main(){

string name;

cout<<"Enter your name: \n";
getline (cin , name);

cout << name.at(5);

    return 0;
}
