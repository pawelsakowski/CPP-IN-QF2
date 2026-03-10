// Vanilla3.cpp

#include "vanilla3.h"

VanillaOption::VanillaOption(const PayOffBridge &the_payoff_, double expiry_) : the_payoff(the_payoff_), expiry(expiry_)
{
}

double VanillaOption::get_expiry() const
{
    return expiry;
}

double VanillaOption::get_option_payoff(double spot) const
{
    return the_payoff(spot);
}
