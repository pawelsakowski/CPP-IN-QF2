#ifndef PAYOFF_BRIDGE_H
#define PAYOFF_BRIDGE_H

#include "payoff4.h"

class PayOffBridge
{
public:
    PayOffBridge(const PayOffBridge &original);
    PayOffBridge(const PayOff &innerPayOff);

    inline double operator()(double spot) const;
    ~PayOffBridge();
    PayOffBridge &operator=(const PayOffBridge &original);

private:
    PayOff *thePayOffPtr;
};

inline double PayOffBridge::operator()(double spot) const
{
    return thePayOffPtr->operator()(spot);
}

#endif
