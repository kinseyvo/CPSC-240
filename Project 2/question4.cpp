#include <iostream>
using namespace std;

int main() {

	int inputNum, third, second, first, sum;
	int hundred = 100, ten = 10, one = 1;
	
	cout << "Enter a 3 digit int number: ";
	cin >> inputNum;

	_asm
	{
		mov eax, inputNum; // Assuming inputNum = 358, eax = 358
		cdq                     // edx:eax = 358
		idiv hundred       // eax = 358 / 100 = 3, remainder = 58 = edx
		mov third, eax     // third = 3

		mov eax, edx    // eax = 58
		cdq             // edx:eax = 58
		idiv ten        // eax = 58 / 10 = 5, remainder = 8 = edx
		mov second, eax // second = 5

		mov eax, edx   // eax = 8
		mov first, eax // first = 8

		add eax, second // eax = 8 + 5
		add eax, third  // eax = 8 + 5 + 3
		mov sum, eax    // sum = 8 + 5 + 3
	}
	
	cout << "  The total of digits in " << inputNum << " is " << sum << endl;
	return 0;
}
