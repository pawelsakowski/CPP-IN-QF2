#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

// general function for mean
double get_vec_mean(std::vector<double> this_vec)
{

	double runningSum = 0.0;
	int this_size = this_vec.size();

	for (int i = 0; i < this_size; i++)
	{
		runningSum += this_vec[i];
	}

	return runningSum / double(this_size);
}

// general function for standard deviation
double get_vec_stddev(std::vector<double> this_vec)
{

	double runningSum = 0.0;
	int this_size = this_vec.size();
	double thisMean = get_vec_mean(this_vec);

	for (int i = 0; i < this_size; i++)
	{
		runningSum += pow((this_vec[i] - thisMean), 2);
	}

	return sqrt(runningSum / (this_size - 1));
}

void print_results(std::vector<std::vector<double>> results)
{
	for (unsigned long i = 0; i < results.size(); i++)
	{
		for (unsigned long j = 0; j < results[i].size(); j++)
		{
			std::cout << results[i][j] << " ";
		}
		std::cout << "\n";
	}
}