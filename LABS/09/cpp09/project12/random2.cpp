#include <cstdlib>
#include "random2.h"
#include "normals.h"

using namespace std;

void RandomBase::get_gaussians(MJArray &variates)
{
    get_uniforms(variates);

    for (unsigned long i = 0; i < dimensionality; i++)
    {
        double x = variates[i];
        variates[i] = InverseCumulativeNormal(x);
    }
}

void RandomBase::reset_dimensionality(unsigned long new_dimensionality)
{
    dimensionality = new_dimensionality;
}

RandomBase::RandomBase(unsigned long dimensionality_)
    : dimensionality(dimensionality_)
{
}
