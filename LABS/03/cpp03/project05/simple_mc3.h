#ifndef SIMPLEMC3_H
#define SIMPLEMC3_H

#include "vanilla1.h"

double SimpleMonteCarlo3(VanillaOption theOption,
						 double spot,
						 double vol,
						 double r,
						 unsigned long numberOfPaths);

#endif
