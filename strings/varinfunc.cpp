#include <iostream>

using namespace std;

void happybd(string name);// name refered

int main(){
//  name is a local variable defined for int main function
    string name= "Aryan";
    happybd(name); //name assigned to be used inside happybd func whenever it is invoked

    return 0;
}

// func that is going to be using the variable needs to have the same parameters
// as the variable that is going to be passed to it

void happybd(string name){   //references are renameable
    cout<<"***Happy Birthday*** "<< name << endl;
}
