#include <iostream>
#include <string>
using namespace std;
string name;
int main(){
    
    while(name.empty()){
      cout << "Enter your name: ";
        getline (cin , name);  
    }
        
    cout<<"Hello" << name;
    return 0;
}
