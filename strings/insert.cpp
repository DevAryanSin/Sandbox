#include <iostream>
#include <string>

using namespace std;
//name.insert(0, "@") 0 pos par @ daaldiya (pos, "replacement")
int main(){

string name;

cout<<"Enter your name: \n";
getline (cin , name);

name.insert(0 , "@");
cout << name;

    return 0;
}
