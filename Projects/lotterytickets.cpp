#include <iostream>
#include <ctime>

using namespace std;

int main(){

    srand(time(0)); // Current time as a seed
    int randNum = rand() % 5 + 1; // random number through 1 and 5


    switch (randNum){
        case 1: cout << "You win a bumper sticker!\n ";
        break;
        case 2: cout << "You win a tshirt!\n ";
        break;
        case 3: cout << "You win a free lunch!\n ";
        break;
        case 4: cout << "You win a gift card!\n ";
        break;
        case 5: cout << "You win concert tickets!\n ";
        break;
    }

    return 0;
}
