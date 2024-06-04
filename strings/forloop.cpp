#include <iostream>
using namespace std;
//Forloop: 1. index = counter
//         2. stopping condition = range
//         3. increment/decrement = step
//         4. ek loop complete hone ke baad value i ki increase ya decrease hoti rahegi
//         5. loop tab tak chalega jab tak stopping condition true ho
int main()
{
    for(int i = 1; i <=5 ; i++ ){
        cout <<"HAPPY NEW YEAR!\n";

    }

    return 0;
}

// or

// This one counts to ten and then prints statement
#include <iostream>

using namespace std;

int main()
{
    for(int i = 1; i <=10 ; i++ ){
        cout <<i << '\n';
    }
     
     cout << "HAPPY NEW YEAR!";
    return 0;
}

// or

#include <iostream>
using namespace std;

int main()
{
    for(int i = 10; i >=0 ; i-- ){
        cout << i << '\n';

    }
    cout <<"HAPPY NEW YEAR!\n";

    return 0;
}
