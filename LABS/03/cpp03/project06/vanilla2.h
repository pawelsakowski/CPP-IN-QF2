#ifndef VANILLA_2_H
#define VANILLA_2_H

#include "payoff4.h"

class VanillaOption
{
public:
    VanillaOption(const PayOff &the_payoff_, double expiry_);
    VanillaOption(const VanillaOption &original);

    VanillaOption &operator=(const VanillaOption &original);
    ~VanillaOption();

    double get_expiry() const;
    double get_option_payoff(double spot) const;

private:
    double expiry;
    PayOff *the_payoff_ptr;
};

#endif
