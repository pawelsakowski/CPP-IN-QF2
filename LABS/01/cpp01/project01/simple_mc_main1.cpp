// simple_mc_main1.cpp
// requires random1.cpp

#include "random1.h"
#include <iostream>
#include <cmath>

// prototype of the function
double simple_monte_carlo1(double expiry,
						   double strike,
						   double spot,
						   double vol,
						   double r,
						   unsigned long number_of_paths);

// main function
int main()
{

	double expiry;
	double strike;
	double spot;
	double vol;
	double r;
	unsigned long number_of_paths;

	std::cout << "\nEnter expiry\n";
	std::cin >> expiry;

	std::cout << "\nEnter strike\n";
	std::cin >> strike;

	std::cout << "\nEnter spot\n";
	std::cin >> spot;

	std::cout << "\nEnter volatility\n";
	std::cin >> vol;

	std::cout << "\nEnter risk-free rate\n";
	std::cin >> r;

	std::cout << "\nNumber of paths\n";
	std::cin >> number_of_paths;

	double result = simple_monte_carlo1(expiry,
										strike,
										spot,
										vol,
										r,
										number_of_paths);

	std::cout << "The price of European call is " << result << "\n";

	double tmp;
	std::cin >> tmp;

	return 0;
}

// definition of the function
double simple_monte_carlo1(double expiry,
						   double strike,
						   double spot,
						   double vol,
						   double r,
						   unsigned long number_of_paths)
{

	double variance = vol * vol * expiry;
	double root_variance = sqrt(variance);
	double ito_correction = -0.5 * variance;

	double moved_spot = spot * exp(r * expiry + ito_correction);
	double this_spot;
	double running_sum = 0;

	for (unsigned long i = 0; i < number_of_paths; i++)
	{
		double this_gaussian = get_one_gaussian_by_box_muller();
		this_spot = moved_spot * exp(root_variance * this_gaussian);
		double this_payoff = this_spot - strike;
		// this_payoff = this_payoff > 0 ? this_payoff : 0;
		if (this_payoff > 0)
			running_sum += this_payoff;
	}

	double mean = running_sum / number_of_paths;
	// mean *= exp(-r * expiry);
	mean = mean * exp(-r * expiry);
	return mean;
}
