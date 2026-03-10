// Parameters.cpp

#include "parameters.h"

Parameters::Parameters(const ParametersInner &innerObject)
{
    InnerObjectPtr = innerObject.clone();
}

Parameters::Parameters(const Parameters &original)
{
    InnerObjectPtr = original.InnerObjectPtr->clone();
}

Parameters &Parameters::operator=(const Parameters &original)
{
    if (this != &original)
    {
        delete InnerObjectPtr;
        InnerObjectPtr = original.InnerObjectPtr->clone();
    }
    return *this;
}

Parameters::~Parameters()
{
    delete InnerObjectPtr;
}

double Parameters::get_mean(double time1, double time2) const
{
    double total = get_integral(time1, time2);
    return total / (time2 - time1);
}

double Parameters::get_root_mean_square(double time1, double time2) const
{
    double total = get_integral_square(time1, time2);
    return total / (time2 - time1);
}

ParametersConstant::ParametersConstant(double constant_)
{
    constant = constant_;
    constant_square = constant_ * constant_;
}

ParametersInner *ParametersConstant::clone() const
{
    return new ParametersConstant(*this);
}

double ParametersConstant::get_integral(double time1, double time2) const
{
    return (time2 - time1) * constant;
}

double ParametersConstant::get_integral_square(double time1, double time2) const
{
    return (time2 - time1) * constant_square;
}
