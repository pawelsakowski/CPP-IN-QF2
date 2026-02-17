//
// example01.cpp
//
// Functors - classes that behave like functions.

#include <iostream>
using namespace std;

class FunctorClass
{
public:
	// constructor declaration
	FunctorClass(int a = 0, int b = 0);
	// method declaration - overloaded () operator
	int operator()(int a, int b);

private:
	// members declaration;
	int a_;
	int b_;
};

// Definition of constructor
FunctorClass::FunctorClass(int a, int b)
	: a_(a), b_(b)
{
}

// Definition of class method (function).
// We use an overloaded operator() here.
// The () operator takes two arguments and returns a sum of them.
// Hence, the object of FunctorClass behaves like a function!
int FunctorClass::operator()(int a, int b)
{
	return (a + b);
}

// Main function
int main()
{
	int first, second;

	cout << "Enter first integer" << endl;
	cin >> first;
	cout << "Enter second integer" << endl;
	cin >> second;

	// a new object of FunctorClass is created
	FunctorClass my_functor(first, second);
	// the object my_functor behaves as a function
	int sum = my_functor(first, second);
	cout << "The sum of these two integers is " << sum << endl;

	// Wait for the user to press Enter or Return.
	double tmp;
	std::cin >> tmp;

} // end of main function
