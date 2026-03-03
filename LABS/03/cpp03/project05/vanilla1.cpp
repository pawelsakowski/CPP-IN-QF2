#include "vanilla1.h"

VanillaOption::VanillaOption(PayOff &thePayOff_, double expiry_) : thePayOff(thePayOff_)
{
    expiry = expiry_;
}

double VanillaOption::get_expiry() const
{
    return expiry;
}

double VanillaOption::get_option_payoff(double spot) const
{
    return thePayOff(spot);
}
