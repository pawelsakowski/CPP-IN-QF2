#include "double_digital.h"

PayOffDoubleDigital::PayOffDoubleDigital(double lower_level_, double upper_level_)
{
    lower_level = lower_level_;
    upper_level = upper_level_;
}

double PayOffDoubleDigital::operator()(double spot) const
{
    if (spot <= lower_level)
        return 0;
    if (spot >= upper_level)
        return 0;
    return 1;
}
