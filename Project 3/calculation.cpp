#include <iostream>
using namespace std;

int main() {
	short a, b, c, d, e, f, X, Y;
	short temp1, temp2, temp3, temp4;

	cout << "This program solves the system\n";
	cout << "\taX + bY = c\n\tdX + eY = f\n";
	cout << "Enter the values of a,b, and c: ";
	cin >> a >> b >> c;
	cout << "Enter the values of d,e, and f: ";
	cin >> d >> e >> f;

	_asm {
		//X
		mov ax, c;		//ax = c
		imul e;			//ax = ce
		mov bx, b;		//bx = b
		imul bx, f;		//bx = bf
		sub ax, bx;		//ax - bx = ce - bf
		mov temp1, ax;	//temp1 = ce - bf
		mov cx, a;		//cx = a
		imul cx, e;		//cx = ae
		mov dx, b;		//dx = b
		imul dx, d;		//dx = bd
		sub cx, dx;		//cx - dx = ae - bd
		mov temp2, cx;  //temp2 = ae - bd
		cwd;
		idiv temp2;		
		mov X, ax;		//X = temp1/temp2

		//Y
		mov ax, a;		//ax = a
		imul f;			//ax = af
		mov bx, c;		//bx = c
		imul bx, d;		//bx = cd
		sub ax, bx;		//ax - bx = af - cd
		mov temp3, ax;	//temp3 = af - cd
		mov cx, a;		//cx = a
		imul cx, e;		//cx = ae
		mov dx, b;		//dx = b
		imul dx, d;		//dx = bd
		sub cx, dx;		//cx - dx = ae - bd
		mov temp4, cx;  	//temp4 = ae - bd
		cwd;
		idiv temp4;
		mov Y, ax;		//Y = temp3/temp4
	}

	cout << "X = " << X << endl;
	cout << "Y = " << Y << endl;
}
