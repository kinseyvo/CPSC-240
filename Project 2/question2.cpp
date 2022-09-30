#include <iostream>
using namespace std;

int main() {
	int a, b, c, h, len, width, tPerimeter, tArea, rPerimeter, rArea;
	int two = 2;

	cout << "Enter the values of a, b, c and h for the triangle: ";
	cin >> a >> b >> c >> h;

	cout << "Enter the length and the width of the rectangle: ";
	cin >> len >> width;
	
	_asm
	{
		mov eax, a  // eax = a
		add eax, b  // eax = a + b
		add eax, c  // eax = a + b + c
		mov tPerimeter, eax // tPerimeter = a + b + c

		mov eax, c // eax = c
		imul h     // eax = c * h
		cdq        // make cdq be 64 bit.
		idiv two   // eax = (c * h) / 2
		mov tArea, eax // tArea = (c * h) / 2

		mov eax, len  // eax = len
		add eax, width // eax = len + width
		imul two // eax = 2(len + width)
		mov rPerimeter, eax // rPerimeter = 2(len + width)

		mov eax, len // eax = len
		imul width // eax = len * width
		mov rArea, eax // rArea = len * width
	}
	
	cout << "\n      Triangle\n               Area..................." << tArea << "\n               Perimeter.............." << tPerimeter << endl;
	cout << "\n      Rectangle\n               Area..................." << rArea << "\n               Perimeter.............." << rPerimeter << endl;
	return 0;
}
