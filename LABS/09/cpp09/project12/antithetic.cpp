#include "antithetic.h"
#include <iostream>

AntiThetic::AntiThetic(const Wrapper<RandomBase> &innerGenerator)
    : RandomBase(*innerGenerator),
      InnerGenerator(innerGenerator)
{
    InnerGenerator->reset();
    OddEven = true;
    NextVariates.resize(get_dimensionality());
}

RandomBase *AntiThetic::clone() const
{
    return new AntiThetic(*this);
}

void AntiThetic::get_uniforms(MJArray &variates)
{
    if (OddEven)
    {
        InnerGenerator->get_uniforms(variates);

        for (unsigned long i = 0; i < get_dimensionality(); i++)
            NextVariates[i] = 1.0 - variates[i];

        OddEven = false;
    }
    else
    {
        variates = NextVariates;
        OddEven = true;
    }

    // std::cout << "the current variate is " << variates[0] << "\n";
}

void AntiThetic::set_seed(unsigned long seed)
{
    InnerGenerator->set_seed(seed);
    OddEven = true;
}

void AntiThetic::skip(unsigned long number_of_paths)
{
    if (number_of_paths == 0)
        return;

    if (OddEven)
    {
        OddEven = false;
        number_of_paths--;
    }

    InnerGenerator->skip(number_of_paths / 2);

    if (number_of_paths % 2)
    {
        MJArray tmp(get_dimensionality());
        get_uniforms(tmp);
    }
}

void AntiThetic::reset_dimensionality(unsigned long new_dimensionality)
{
    RandomBase::reset_dimensionality(new_dimensionality);
    NextVariates.resize(new_dimensionality);
    InnerGenerator->reset_dimensionality(new_dimensionality);
}

void AntiThetic::reset()
{
    InnerGenerator->reset();
    OddEven = true;
}
