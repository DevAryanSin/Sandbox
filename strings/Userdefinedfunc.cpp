#include <iostream>
using namespace std;

// to create a new function - void func(){what goes within the function}
// to invoke a function - func() in another function
// Function - a block of reuseable code

// function defined before invoking

// void happyBirthday(){
//     cout <<"Happy Birthday to you!!!\n";
//     cout <<"Happy Birthday to you!!!\n";
//     cout <<"Happy Birthday dear you!!!\n";
//     cout <<"Happy Birthday to you!!!\n\n";

// }

// int main(){

//     happyBirthday();
//     happyBirthday();
//     happyBirthday();



//     return 0;
// }

// function defined after invoking

void happybd();

int main(){
    happybd();
}
void happybd(){
    cout<<"Happpy birtday";
}
