// simple_mc_main2.cpp

#include "simple_mc.h"
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

	cout << "\nEnter vol\n";
	cin >> vol;

	cout << "\nEnter r\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> number_of_paths;

	Payoff call_payoff(strike, Payoff::Call);
	Payoff put_payoff(strike, Payoff::Put);

	double result_call = simple_monte_carlo(call_payoff,
											expiry,
											spot,
											vol,
											r,
											number_of_paths);

	double result_put = simple_monte_carlo(put_payoff,
										   expiry,
										   spot,
										   vol,
										   r,
										   number_of_paths);

	cout << "\nthe prices are:\n"
		 << result_call << " for the call\n"
		 << result_put << " for the put\n";

	double tmp;
	cin >> tmp;

	return 0;
}
