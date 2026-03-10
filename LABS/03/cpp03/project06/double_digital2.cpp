// DoubleDigital2.cpp

#include "double_digital2.h"

// implementation of the constructor
PayOffDoubleDigital::PayOffDoubleDigital(double lower_level_, double upper_level_)
{
    lower_level = lower_level_;
    upper_level = upper_level_;
}

// implementation of the method
double PayOffDoubleDigital::operator()(double spot) const
{
    if (spot <= lower_level)
        return 0;
    if (spot >= upper_level)
        return 0;

    return 1;
}

// implementation of the virtual copy constructor
PayOff *PayOffDoubleDigital::clone() const
{
    return new PayOffDoubleDigital(*this);
}
