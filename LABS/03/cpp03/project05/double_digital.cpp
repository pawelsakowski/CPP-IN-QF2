#include "double_digital.h"

PayOffDoubleDigital::PayOffDoubleDigital(double lowerLevel_, double upperLevel_)
{
    lowerLevel = lowerLevel_;
    upperLevel = upperLevel_;
}

double PayOffDoubleDigital::operator()(double spot) const
{
    if (spot <= lowerLevel)
        return 0;
    if (spot >= upperLevel)
        return 0;
    return 1;
}
