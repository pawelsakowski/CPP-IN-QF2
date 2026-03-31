#ifndef ANTITHETIC_H
#define ANTITHETIC_H

#include "random2.h"
#include "wrapper.h"

class AntiThetic : public RandomBase
{

public:
    AntiThetic(const Wrapper<RandomBase> &inner_generator);
    virtual RandomBase *clone() const;
    virtual void get_uniforms(MJArray &variates);
    virtual void skip(unsigned long number_of_paths);
    virtual void set_seed(unsigned long seed);
    virtual void reset_dimensionality(unsigned long new_dimensionality);
    virtual void reset();

private:
    Wrapper<RandomBase> InnerGenerator;
    bool OddEven;
    MJArray NextVariates;
};

#endif
