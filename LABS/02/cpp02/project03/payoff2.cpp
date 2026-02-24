#include "payoff3.h"
#include <algorithm>

PayOffCall::PayOffCall(double strike) : strike(strike) {}

double PayOffCall::operator()(double spot) const
{
    return std::max(spot - strike, 0.0);
}

PayOffPut::PayOffPut(double strike) : strike(strike) {}

double PayOffPut::operator()(double spot) const
{
    return std::max(strike - spot, 0.0);
}
