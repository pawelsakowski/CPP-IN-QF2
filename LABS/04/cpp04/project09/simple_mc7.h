#ifndef SIMPLE_MC7_H
#define SIMPLE_MC7_H

#include "vanilla3.h"
#include "parameters.h"
#include "statistics_mc.h"

void simple_monte_carlo7(const VanillaOption &the_option,
						 double spot,
						 const Parameters &vol,
						 const Parameters &r,
						 unsigned long number_of_paths,
						 StatisticsMC &gatherer);

#endif
