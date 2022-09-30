#include <iostream>
using namespace std;

int a[5] = { 9, 3, 22, 8, 1 };
int i, j;


int main() {

    cout << "Original array a: ";
    for (int val : a)
        cout << val << " ";
    cout << endl;  

    _asm {

        mov i, 0;       // i = 0

    stepLoop:
        cmp i, 5;       // Compare i to 5
        je done;        // If i == 5, jump to done
        inc i;          // i++
        mov j, 0;       // Set j to 0.
        lea esi, [a];   // Set esi to the first index.

    compareLoop:
        cmp j, 5;       // Compare j to 5
        je stepLoop;    // If j == 5, jump back to stepLoop
        mov eax, [esi]; // eax = a[j]
        add esi, 4;     // Move on to the next index
        cmp eax, [esi]; // Compare a[j] to a[j + 1]
        jg Swap;        // If a[j] > a[j + 1], jump to Swap
        inc j;          // j++
        jmp compareLoop;// Jump back to compareLoop

    Swap:
        mov ebx, [esi];  // ebx = a[j + 1]
        xchg [esi], eax; // a[j + 1] = a[j]
        sub esi, 4;      // Come back to a[j]
        xchg [esi], ebx; // a[j] = a[j + 1]
        inc j;           // j++
        jmp compareLoop; // Jump back to compareLoop.

    done:

    }

    
    cout << "Sorted array a:   ";
    for (int val : a)
        cout << val << " ";
    cout << endl;
    
    return 0;
}
