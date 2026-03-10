#ifndef DOUBLE_DIGITAL2_H
#define DOUBLE_DIGITAL2_H

#include "payoff4.h"

class PayOffDoubleDigital : public PayOff
{
public:
    PayOffDoubleDigital(double lower_level_, double upper_level_);

    virtual double operator()(double spot) const;
    virtual ~PayOffDoubleDigital() {};
    virtual PayOff *clone() const;

private:
    double lower_level;
    double upper_level;
};

#endif
