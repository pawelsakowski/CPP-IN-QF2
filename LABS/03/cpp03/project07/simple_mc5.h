#ifndef SIMPLE_MC5_H
#define SIMPLE_MC5_H

#include "vanilla3.h"

double simple_monte_carlo5(const VanillaOption &the_option,
						   double spot,
						   double vol,
						   double r,
						   unsigned long number_of_paths);

#endif
