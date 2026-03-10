#ifndef SIMPLE_MC4_H
#define SIMPLE_MC4_H

#include "vanilla2.h"

double simple_monte_carlo4(const VanillaOption &the_option,
						   double spot,
						   double vol,
						   double r,
						   unsigned long number_of_paths);

#endif
