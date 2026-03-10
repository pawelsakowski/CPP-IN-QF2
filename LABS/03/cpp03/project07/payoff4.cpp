// PayOff3.cpp

#include "payoff4.h"
#include "minmax.h"

PayOffCall::PayOffCall(double strike_)
{
    strike = strike_;
}

double PayOffCall::operator()(double spot) const
{
    return max(spot - strike, 0.0);
}

PayOff *PayOffCall::clone() const
{
    return new PayOffCall(*this);
}

double PayOffPut::operator()(double spot) const
{
    return max(strike - spot, 0.0);
}

PayOffPut::PayOffPut(double strike_) : strike(strike_)
{
}

PayOff *PayOffPut::clone() const
{
    return new PayOffPut(*this);
}
