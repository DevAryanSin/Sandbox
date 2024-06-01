#include <iostream>

int main() {
     using namespace std;
     
     int temp;
     bool sunny= false;
     cout<< "Enter temperature: ";
     cin >> temp;
     
     
     if (temp <= 0 || temp>=30){
     cout<< "The temp is bad! \n ";
     }
     
     else{
         cout<<"The temp is good! \n ";
     }
     
     if (!sunny){
         cout<<"It is sunny outside";
              }
        else{
            cout<<"It is cloudy outside";
        }


    return 0;
}
