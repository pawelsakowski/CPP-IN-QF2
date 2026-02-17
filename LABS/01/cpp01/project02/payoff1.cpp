// payoff1.cpp

#include "payoff1.h"
#include "min_max.h"

Payoff::Payoff(double strike, OptionType option_type)
    : strike_(strike), option_type_(option_type)
{
}

double Payoff::operator()(double spot) const
{
    switch (option_type_)
    {
    case Call:
        return max(spot - strike_, 0.0);

    case Put:
        return max(strike_ - spot, 0.0);

    default:
        throw("Unknown option type found.");
    }
}
