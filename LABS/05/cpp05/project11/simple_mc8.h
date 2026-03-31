#ifndef SIMPLE_MC8_H
#define SIMPLE_MC8_H

#include "vanilla3.h"
#include "parameters.h"
#include "random2.h"
#include "statistics_mc.h"

void simple_monte_carlo8(const VanillaOption &the_option,
						 double spot,
						 const Parameters &vol,
						 const Parameters &r,
						 unsigned long number_of_paths,
						 StatisticsMC &gatherer,
						 RandomBase &generator);

#endif
