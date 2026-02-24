// PayOff.cpp

#include "payoff3.h"
#include "minmax.h"

// definition of a constructor
PayOffCall::PayOffCall(double strike_)
{
    strike = strike_;
}

// definition of a function
double PayOffCall::operator()(double spot) const
{
    return max(spot - strike, 0.0);
}

// definition of a constructor
PayOffPut::PayOffPut(double strike_)
{
    strike = strike_;
}

// definition of a function
double PayOffPut::operator()(double spot) const
{
    return max(strike - spot, 0.0);
}
