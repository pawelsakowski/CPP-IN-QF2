#ifndef DOUBLE_DIGITAL_H
#define DOUBLE_DIGITAL_H

#include "payoff3.h"

class PayOffDoubleDigital : public PayOff
{
public:
    PayOffDoubleDigital(double lowerLevel_, double upperLevel_);
    virtual double operator()(double spot) const;
    virtual ~PayOffDoubleDigital() {};

private:
    double lowerLevel;
    double upperLevel;
};

#endif
