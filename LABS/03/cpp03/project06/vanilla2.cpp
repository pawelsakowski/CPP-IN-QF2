// Vanilla2.cpp

#include "vanilla2.h"

// implementation of the virtual copy constructor
VanillaOption::VanillaOption(const PayOff &the_payoff_, double expiry_)
{
    expiry = expiry_;
    the_payoff_ptr = the_payoff_.clone();
}

// implementation of the method
double VanillaOption::get_expiry() const
{
    return expiry;
}

// implementation of the method
double VanillaOption::get_option_payoff(double spot) const
{
    return (*the_payoff_ptr)(spot);
}

VanillaOption::VanillaOption(const VanillaOption &original)
{
    expiry = original.expiry;
    the_payoff_ptr = original.the_payoff_ptr->clone();
}

VanillaOption &VanillaOption::operator=(const VanillaOption &original)
{
    if (this != &original)
    {
        expiry = original.expiry;
        delete the_payoff_ptr;
        the_payoff_ptr = original.the_payoff_ptr->clone();
    }
    return *this;
}

// implementation of the destructor
VanillaOption::~VanillaOption()
{
    delete the_payoff_ptr;
}
