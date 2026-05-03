#ifndef RANDOM2_H
#define RANDOM2_H

#include "arrays.h"

class RandomBase
{
public:
    RandomBase(unsigned long dimensionality);

    inline unsigned long get_dimensionality() const;

    virtual RandomBase *clone() const = 0;
    virtual void get_uniforms(MJArray &variates) = 0;
    virtual void skip(unsigned long numberOfPaths) = 0;
    virtual void set_seed(unsigned long Seed) = 0;
    virtual void reset() = 0;

    virtual void get_gaussians(MJArray &variates);
    virtual void reset_dimensionality(unsigned long NewDimensionality);
    virtual ~RandomBase() {};

private:
    unsigned long dimensionality;
};

unsigned long RandomBase::get_dimensionality() const
{
    return dimensionality;
}

#endif
