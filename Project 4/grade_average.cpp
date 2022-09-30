#include <iostream>
using namespace std;

int score, result, sum = 0;
int counter = 0;

void askforScore() {
    cout << "\tEnter your score (-1) to stop: ";
    cin >> score;
}

int main()
{
    cout << "Let's compute your score's average:" << endl;
    _asm {
    whileLoop:
        call askforScore;
        mov ebx, score;     //ebx = score
        cmp ebx, -1;        //compare score and -1
        je exitLoop;        //if equal, jump to exitLoop
        add sum, ebx;       //sum = sum + ebx
        inc counter         //counter++
        jmp whileLoop;      //jump to whileLoop
    exitLoop:
        mov eax, sum;       //eax = sum
        cdq;
        idiv counter;       //eax = eax/counter
        mov result, eax;    //result = eax
    }

    cout << "\t\tYour average is " << result << endl;
    return 0;
}
