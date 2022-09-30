#include <iostream>
using namespace std;

int main() {
	//total = 2drink + 4sandwich
	short d_price = 2, s_price = 4, drink, sandwich, total;

	cout << "How many drinks? ";
	cin >> drink;
	cout << "How many sandwiches? ";
	cin >> sandwich;

	_asm
	{
		mov ax, drink;
		imul d_price;
		mov bx, sandwich;
		imul bx, s_price;
		add ax, bx;
		mov total, ax;
	}

	cout << "Your total bill: $" << total;
	return 0;
}
