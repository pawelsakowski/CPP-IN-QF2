#ifndef SIMPLE_MC2_H
#define SIMPLE_MC2_H

#include "payoff3.h"

double simple_monte_carlo2(const PayOff &payOff,
                           double expiry,
                           double spot,
                           double vol,
                           double r,
                           unsigned long number_of_paths);
#endif