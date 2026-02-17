// simple_mc.h

#ifndef SIMPLE_MC_H
#define SIMPLE_MC_H

#include "payoff1.h"

double simple_monte_carlo(const Payoff& the_payoff,
                          double expiry,
                          double spot,
                          double vol,
                          double r,
                          unsigned long number_of_paths);

#endif
