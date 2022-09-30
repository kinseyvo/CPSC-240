#include <iostream>
using namespace std;

int i = 0;
int total, medium, blue = 0;
int b[4][4] = { {10, 20, 30, 40}, {20, 10, 40, 30}, {5, 15, 20, 25}, {30, 25, 20, 15} };

void display() {
    cout << "Total number of shirts: " << total << endl;
    cout << "Total number of Medium shirts: " << medium << endl;
    cout << "Total number of Blue shirts: " << blue << endl;
}

int main()
{
    _asm {
        mov eax, 0;      //eax = 0
        mov i, 0;           //i = 0
        lea esi, [b];       //esi = [b]

    //Total number of shirts
    forLoop:
        cmp i, 16;          	//compare i and 16
        Je done;           	//if i == 16, jump to done
        add eax, [esi];     //eax += b[][]
        inc i;       		//i++
        add esi, 4;           //esi += 4
        Jmp forLoop;       //jump to forLoop
    done:
        mov total, eax;     //total = eax


       //Total number of Medium shirts
        mov ebx, 0;         //ebx = 0
        lea esi, [b];      	//esi = [b]
        add esi, 4;     	//esi += 4
        add ebx, [esi];     //ebx += b[][]
        add esi, 16;         //esi += 16
        add ebx, [esi];
        add esi, 16;
        add ebx, [esi];
        add esi, 16;
        add ebx, [esi];
        mov medium, ebx;   //medium = ebx
  

        //Total number of Blue shirts
        mov ecx, 0;        //ecx = 0
        mov i, 0;             //i = 0
        lea esi, [b];         //esi = [b]
        add esi, 32;        //esi += 32
    forLoop2:
        cmp i, 4;          	//compare i and 4
        Je done2;           //if i == 4, jump to done2
        add ecx, [esi];    //ecx += b[][]
        inc i;                   //i++
        add esi, 4;          //esi += 4
        Jmp forLoop2;   //jump to forLoop2
    done2:
        mov blue, ecx;   //blue = ecx
    }

    display();
    return 0;
}
