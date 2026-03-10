// PayOffBridge.cpp

#include "payoff_bridge.h"
#include <iostream>

PayOffBridge::PayOffBridge(const PayOffBridge &original)
{
    thePayOffPtr = original.thePayOffPtr->clone();
}

PayOffBridge::PayOffBridge(const PayOff &innerPayOff)
{
    thePayOffPtr = innerPayOff.clone();
}

PayOffBridge::~PayOffBridge()
{
    delete thePayOffPtr;
}

PayOffBridge &PayOffBridge::operator=(const PayOffBridge &original)
{
    if (this != &original)
    {
        delete thePayOffPtr;
        thePayOffPtr = original.thePayOffPtr->clone();
        std::cout << "assignment operator has been used!\n";
    }

    return *this;
}
