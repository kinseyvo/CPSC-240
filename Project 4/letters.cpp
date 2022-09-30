#include <iostream>
using namespace std;

short numOfUppers = 0, numOfLowers = 0;
short total;
char c;

void askSentence() {
    cout << "Enter a sentence: ";
}

void readChar() {
    c = cin.get();
}

int main() {
  
    _asm {
        call askSentence;

    whileLoop:
        call readChar;
        cmp c, '\n';        // Compare c to \n
        je exitLoop;        // If c == \n, move to exit (end of sentence)
        cmp c, ' ';         // Compare c to empty space
        je whileLoop;       // If c is empty space, jump to whileLoop
        cmp c, 90           // Compare c to 90, since ascii codes for uppercase letters are 65 - 90.
        jle upperCounter;   // If c is less than or equal to 91, jump to upperCounter.
        cmp c, 97           // Compare c to 97, since ascii codes for lowercase letters are 97 - 122
        jge lowerCounter;   // If c is greater than or equal to 97, jump to lowerCounter.
        Jmp whileLoop;      // Jump back to whileLoop otherwise.

    upperCounter:
        cmp c, 65;          // Compare c to 65
        jl whileLoop;       // If c is less than 65, jump back to whileLoop.
        inc numOfUppers;    // Increment the number of uppercase.
        jmp whileLoop;      // Jump back to whileLoop.

    lowerCounter:
        cmp c, 122          // Compare c to 122
        jg whileLoop;       // If c is greater than 122, jump back to whileLoop.
        inc numOfLowers;    // Increment the number of lowercase.
        jmp whileLoop;      // Jump back to whileLoop.

    exitLoop:
    }

    cout << "\tNo. of uppercase letters = " << numOfUppers << endl;
    cout << "\tNo. of lowercase letters = " << numOfLowers << endl;

    return 0;
}
