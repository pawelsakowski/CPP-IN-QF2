#ifndef PARK_MILLER_H
#define PARK_MILLER_H

#include "random2.h"

class ParkMiller
{
public:
    ParkMiller(long Seed = 1);

    long get_one_random_integer();
    void set_seed(long Seed);

    static unsigned long max();
    static unsigned long min();

private:
    long seed;
};

class RandomParkMiller : public RandomBase
{
public:
    RandomParkMiller(unsigned long Dimensionality, unsigned long Seed = 1);

    virtual RandomBase *clone() const;
    virtual void get_uniforms(MJArray &variates);
    virtual void skip(unsigned long numberOfPaths);
    virtual void set_seed(unsigned long Seed);
    virtual void reset();
    virtual void reset_dimensionality(unsigned long NewDimensionality);
    virtual ~RandomParkMiller();

private:
    ParkMiller InnerGenerator;
    unsigned long InitialSeed;
    double Reciprocal;
};
#endif
