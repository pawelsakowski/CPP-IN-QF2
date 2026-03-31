#include "park_miller.h"

const long a = 16807;
const long m = 2147483647;
const long q = 127773;
const long r = 2836;

ParkMiller::ParkMiller(long seed_) : seed(seed_)
{
    if (seed == 0)
        seed = 1;
}

void ParkMiller::set_seed(long seed_)
{
    seed = seed_;
    if (seed == 0)
        seed = 1;
}

unsigned long ParkMiller::max()
{
    return m - 1;
}

unsigned long ParkMiller::min()
{
    return 1;
}

long ParkMiller::get_one_random_integer()
{
    long k;
    k = seed / q;
    seed = a * (seed - k * q) - r * k;
    if (seed < 0)
        seed += m;
    return seed;
}

RandomParkMiller::RandomParkMiller(unsigned long dimensionality, unsigned long seed)
    : RandomBase(dimensionality),
      InnerGenerator(seed),
      InitialSeed(seed)
{
    Reciprocal = 1 / (1.0 + InnerGenerator.max());
}

RandomBase *RandomParkMiller::clone() const
{
    return new RandomParkMiller(*this);
}

void RandomParkMiller::get_uniforms(MJArray &variates)
{
    for (unsigned long j = 0; j < get_dimensionality(); j++)
    {
        variates[j] = InnerGenerator.get_one_random_integer() * Reciprocal;
    }
}

void RandomParkMiller::skip(unsigned long number_of_paths)
{
    MJArray tmp(get_dimensionality());
    for (unsigned long j = 0; j < number_of_paths; j++)
        get_uniforms(tmp);
}

void RandomParkMiller::set_seed(unsigned long seed)
{
    InitialSeed = seed;
    InnerGenerator.set_seed(seed);
}

void RandomParkMiller::reset()
{
    InnerGenerator.set_seed(InitialSeed);
}

void RandomParkMiller::reset_dimensionality(unsigned long new_dimensionality)
{
    RandomBase::reset_dimensionality(new_dimensionality);
    InnerGenerator.set_seed(InitialSeed);
}

RandomParkMiller::~RandomParkMiller() {};