#include <iostream>

using namespace std;

void happybd(string name, int age);

int main(){
//  name is a local variable defined for int main function
    string name= "Aryan";
    int age = 21;

    happybd(name, age);  //name assigned to be used inside happybd func whenever it is invoked

    return 0;
}

// func that is going to be using the variable needs to have the same parameters
// as the variable that is going to be passed to it

void happybd(string name, int age){
    cout<<"Happy "<< age <<" Birthday to "<< name << endl;
}
