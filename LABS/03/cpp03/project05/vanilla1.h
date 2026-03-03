#ifndef VANILLA_1_H
#define VANILLA_1_H

#include "payoff3.h"

class VanillaOption
{
public:
    VanillaOption(PayOff &thePayOff_, double expiry_);
    double get_expiry() const;
    double get_option_payoff(double spot) const;

private:
    double expiry;
    PayOff &thePayOff;
};

#endif
