#ifndef DOUBLE_DIGITAL_H
#define DOUBLE_DIGITAL_H

#include "payoff3.h"

class PayOffDoubleDigital : public PayOff
{
public:
    PayOffDoubleDigital(double lower_level_, double upper_level_);
    virtual double operator()(double spot) const;
    virtual ~PayOffDoubleDigital() {};

private:
    double lower_level;
    double upper_level;
};

#endif
