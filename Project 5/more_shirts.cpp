#include <iostream>
using namespace std;

int i = 0;
int total, medium, shortSleeve, red = 0;
int a[3][3][2] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };

void display() {
    cout << "Total number of shirts: " << total << endl;
    cout << "Total number of Medium shirts: " << medium << endl;
    cout << "Total number of short sleeve shirts: " << shortSleeve << endl;
    cout << "Total number of RED shirts: " << red << endl;
}

int main()
{
    _asm {
        mov eax, 0;      //eax = 0
        mov i, 0;           //i = 0
        lea esi, [a];       //esi = [a]

    //Total number of shirts
    forLoop:
        cmp i, 18;           	  //compare i and 18
        Je done;           	  //if i == 18, jump to done
        add eax, [esi];       //eax += a[][]
        inc i;       		  //i++
        add esi, 4;         	  //esi += 4
        Jmp forLoop;        //jump to forLoop
    done:
        mov total, eax;      //total = eax


       //Total number of Medium shirts
        mov ebx, 0;                   //ebx = 0
        lea esi, [a];      	          //esi = [a]
        add ebx, [esi + 8];         //ebx += a[][]
        add ebx, [esi + 12];
        add ebx, [esi + 32];
        add ebx, [esi + 36];
        add ebx, [esi + 56];
        add ebx, [esi + 60];
        mov medium, ebx;        //medium = ebx


        //Total number of short sleeve shirts 
        mov ecx, 0;                  	  //ecx = 0
        mov i, 0;                  	  //i = 0;
        lea esi, [a];              	  //esi = [a]
        add esi, 0;                	  //esi += 0 (starting position)
    forLoop2:
        cmp i, 9;                  	  //compare i and 9
        Je done2;                  	  //if i == 9, jump to done2
        add ecx, [esi];            	  //ecx += a[][]
        inc i;                     	  //i++
        add esi, 8;                	  //esi += 8
        Jmp forLoop2;              	  //jump to forLoop2
    done2:
        mov shortSleeve, ecx;      //shortSleeve = ecx


        //Total number of Red shirts
        mov edx, 0;        	  //edx = 0
        mov i, 0;                //i = 0
        lea esi, [a];      	  //esi = [a]
        add esi, 0;        	  //esi += 0
    forLoop3:
        cmp i, 6;       	 //compare i and 6
        Je done3;          	 //if i == 6, jump to done3
        add edx, [esi];    	 //edx += a[][]
        inc i;             	 //i++
        add esi, 4;        	 //esi += 4
        Jmp forLoop3;     //jump to forLoop3
    done3:
        mov red, edx;      //red = edx
    }

    display();
    return 0;
}
