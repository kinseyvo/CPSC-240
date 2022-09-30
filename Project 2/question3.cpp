#include <iostream>
using namespace std;

int main() {
    //C=5(F-32)/9
    short thirty_two = 32, nine = 9, five = 5, remainder, C, F;
    
    cout << "Enter temperature in Fahrenheit: ";
    cin >> F;

    _asm
    {
        mov ax, F;
        sub ax, thirty_two;
        cwd;
        imul five;
        idiv nine;
        mov C, ax;
        mov remainder, dx;
    }

    cout << F << " F is " << C << " C" << endl;
    return 0;
}
