#ifndef SIMPLEMC3_H
#define SIMPLEMC3_H

#include "vanilla1.h"

double SimpleMonteCarlo3(VanillaOption the_option,
						 double spot,
						 double vol,
						 double r,
						 unsigned long number_of_paths);

#endif
