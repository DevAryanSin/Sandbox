#include <iostream>
#include <string>

using namespace std;
//name.insert(0 , 3) delete characters fromm 0 to 3 (beginning index , ending index)
int main(){

string name;

cout<<"Enter your name: \n";
getline (cin , name);

name.erase(0 , 3);
cout << name;

    return 0;
}
