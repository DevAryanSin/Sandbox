#include <iostream>

using namespace std;

// Break = break out f a loop
// continue = skip current iteration
// only break = tab 13 tak jaake ruk jayega
// only continue = 13 ko skip karega

int main(){

for (int i = 1; i <= 20 ; i ++){
    if(i == 13){
        continue;
    }
    cout << i << '\n';
}


return 0;

}
