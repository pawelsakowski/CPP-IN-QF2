#include "simple_mc2.h"
#include <iostream>
using namespace std;

int main()
{
	double expiry;
	double strike;
	double spot;
	double vol;
	double r;
	unsigned long number_of_paths;

	cout << "\nEnter expiry\n";
	cin >> expiry;

	cout << "\nEnter strike\n";
	cin >> strike;

	cout << "\nEnter spot\n";
	cin >> spot;

	cout << "\nEnter volatility\n";
	cin >> vol;

	cout << "\nEnter risk-free rate\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> number_of_paths;

	// asking the user about the type of the option
	unsigned long option_type;
	cout << "\nEnter 0 for call, otherwise put\n";
	cin >> option_type;

	// Now, we have to create the new object.
	// The problem is that at time of compilation we don't know the type of the option,
	// so we don't know the type of the new object.
	// Previously we solved this by refering to the base class.
	// Now, we use an alternative solution: refering to the yet-non-existing object via a pointer.

	// First, create a pointer of the type PayOff* (the base class!)
	PayOff *payOffPtr;

	// Now, it seems that the natural solution is to apply:

	/*
	if (option_type== 0)
		PayOffCall payOff(strike);
	else
		PayOffPut payOff(strike);

	*/

	// but will not work, beacuse the payOff - although successfully created - is an automatic variable,
	// which automatically disappears as soon as the scope (here: the if else clause) is left.

	// This is why we have to use the 'new' operator, which tells the compiler that we
	// wish to take some memory - while the code is running - and that memory should not
	// be released until we explicitly say so (by using later 'delete' operator).

	if (option_type == 0)
		payOffPtr = new PayOffCall(strike);
	else
		payOffPtr = new PayOffPut(strike);

	// finally we can call the MC function dereferencing the pointer in the first argument.
	double result = simple_monte_carlo2(*payOffPtr,
										expiry,
										spot,
										vol,
										r,
										number_of_paths);

	cout << "\nthe price is " << result << "\n";

	// !!! IMPORTANT !!!
	// We must get rid of every object created by the 'new' operator.
	// If we forget this, the memory will never be freed up, and
	// will slowly leak away until program crashes.
	// Always use 'delete' after 'new'!
	delete payOffPtr;

	// When we call delete, it first calls the destructor of the object.
	// If the destructor is not virtual then it will call the base class destructor.
	// If the object is of an inherited class this may cause problems as the object will not be destroyed properly.
	// This is why we declared the destructor to be virtual (see PayOff.h)
	// The compiler then uses the virtual function table to correctly decide which destructor to call.

	return 0;
}
