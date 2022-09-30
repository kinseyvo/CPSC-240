#include <iostream>
using namespace std;

short sodaPrice = 2, waterPrice = 1, sand10Price = 3, sand12Price = 5, counter = 0;
short numOfCustomers, numOfDrinks, numOfSandwiches, sizeOfSand, total;
char kindOfDrink;

void sandwichOrder() {
	cout << "\tHow many Sandwiches? ";
	cin >> numOfSandwiches;
	cout << "\t\tWhat size of sandwich (10/12 inches)? ";
	cin >> sizeOfSand;
}

void drinkOrder() {
	cout << "\tHow many drinks? ";
	cin >> numOfDrinks;
	cout << "\t\tWhat kind of drink(S=Soda, W=Water)? ";
	cin >> kindOfDrink;
}

void totalBill() {
	cout << "\t\t\tYour total bill = " << total << "\n" << endl;
}

int main() {

	cout << "----------------------7-11 Convenient Store ----------------------" << endl;
	cout << "\nDrinks" << endl;
	cout << "\tSoda(S).......................................................$2" << endl;
	cout << "\tWater (W).....................................................$1" << endl;
	cout << "\nSandwiches" << endl;
	cout << "\t10 inches.....................................................$3 " << endl;
	cout << "\t12 inches.....................................................$5 " << endl;

	cout << "\nEnter the number of customers: ";
	cin >> numOfCustomers;

	_asm {

	orderLoop:
		call drinkOrder;		// Call drinkOrder function
		cmp kindOfDrink, 'S';	// Determine if the drink is soda (Uppercase S)
		je sodaCal;				// If so, jump to soda calculation
		cmp kindOfDrink, 's';	// Determine if the drink is soda (Lowercase s)
		je sodaCal;				// If so, jump to soda calculation

	waterCal:
		mov ax, waterPrice;		// ax = 1
		imul ax, numOfDrinks;	// ax = 1 * number of drinks
		mov total, ax;			// total = 1 * number of drinks
		jmp halfDone;			// Jump to the half point

	sodaCal:
		mov ax, sodaPrice;		// ax = 2
		imul ax, numOfDrinks;	// ax = 2 * number of drinks
		mov total, ax;			// total = 2 * number of drinks

	halfDone:
		call sandwichOrder;		// Call sandwichOrder function
		cmp sizeOfSand, 10;		// Determine if the size is 10 inches
		je size10Cal;			// If so, jump to size 10 calculation

	size12Cal:
		mov ax, sand12Price;	// ax = 5
		imul numOfSandwiches;	// ax = 5 * number of sandwiches
		add total, ax;			// total += 5 * number of sandwiches
		jmp done;				// Jump to the ending point

	size10Cal:
		mov ax, sand10Price;	// ax = 3
		imul numOfSandwiches;	// ax = 3 * number of sandwiches
		add total, ax;			// total += 3 * number of sandwiches 

	done:
		call totalBill;			// Display the total
		inc counter;			// Increment counter
		mov ax, counter;		// ax = counter
		cmp numOfCustomers, ax;	// Compare the number of customers to counter for an additional loop
		jne orderLoop;			// Jump to the starting point if the number of customers is not equal to counter
	}

	return 0;
}
