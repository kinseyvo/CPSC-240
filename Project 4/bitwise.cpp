#include <iostream>
using namespace std;

int numOfPrinters, numOfFloppyDrives, sizeOfRAM;
int a = 52892;  //1100111010011100

int main()
{
    _asm {
        //Number of printers connected to the computer
        mov eax, a;                //eax = a
        mov ebx, 1100000000000000; //ebx = 1100000000000000
        and eax, ebx;              //eax = eax & ebx
        shr eax, 14;               //eax = eax/2
        mov numOfPrinters, eax;    //numOfPrinters = eax & ebx

        //Number of floppy drives
        mov eax, a;                   //eax = a
        mov ebx, 0000000011000000;    //ebx = 0000000011000000
        and eax, ebx;                 //eax = eax & ebx
        shr eax, 6;                   //eax = eax/2
        inc eax;

        cmp eax, 00;
        je oneDerive;
        cmp eax, 01;
        je twoDerive;
        cmp eax, 10;
        je threeDerive;
        cmp eax, 11;
        je fourDerive;

    oneDerive:
        mov eax, 1;
        jmp done;
    twoDerive:
        mov eax, 2;
        jmp done;
    threeDerive:
        mov eax, 3;
        jmp done;
    fourDerive:
        mov eax, 4;
        jmp done;
    done:
        mov numOfFloppyDrives, eax;   //numOfFloppyDrives = eax & ebx

        //Size of RAM
        mov eax, a;                    //eax = a
        mov ebx, 0000000000001100;     //ebx = 0000000000001100
        and eax, ebx;                  //eax = eax & ebx
        shr eax, 2;                    //eax = eax/2

        cmp eax, 00;
        Je Case1;
        cmp eax, 01;
        Je Case2;
        cmp eax, 10;
        Je Case3;
        cmp eax, 11;
        Je Case4;

    Case1:
        mov eax, 16;
        mov sizeOfRAM, eax;
    Case2:
        mov eax, 32;
        mov sizeOfRAM, eax;
    Case3:
        mov eax, 48;
        mov sizeOfRAM, eax;
    Case4:
        mov eax, 64;
        mov sizeOfRAM, eax;
    }

    cout << "Number of printers connected to the computer: " << numOfPrinters << endl;
    cout << "Number of floppy drives: " << numOfFloppyDrives << endl;
    cout << "Size of the RAM: " << sizeOfRAM << endl;

    return 0;
}
