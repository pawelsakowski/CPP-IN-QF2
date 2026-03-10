#ifndef SIMPLE_MC6_H
#define SIMPLE_MC6_H

#include "vanilla3.h"
#include "parameters.h"

double simple_monte_carlo6(const VanillaOption &the_option,
						   double spot,
						   const Parameters &vol,
						   const Parameters &r,
						   unsigned long number_of_paths);

#endif
