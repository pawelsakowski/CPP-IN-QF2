#ifndef VANILLA3_H
#define VANILLA3_H

#include "payoff_bridge.h"

class VanillaOption
{
public:
    VanillaOption(const PayOffBridge &the_payoff_, double expiry_);

    double get_option_payoff(double spot) const;
    double get_expiry() const;

private:
    double expiry;
    PayOffBridge the_payoff;
};

#endif
