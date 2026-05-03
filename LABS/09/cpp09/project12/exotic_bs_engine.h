// ExoticBSEngine.h

#ifndef EXOTIC_BS_ENGINE_H
#define EXOTIC_BS_ENGINE_H

#include "exotic_engine.h"
#include "random2.h"

class ExoticBSEngine : public ExoticEngine
{
public:
    ExoticBSEngine(const Wrapper<PathDependent> &the_product_,
                   const Parameters &r_,
                   const Parameters &d_,
                   const Parameters &vol_,
                   const Wrapper<RandomBase> &the_generator_,
                   double spot_);

    virtual void get_one_path(MJArray &spot_values);
    virtual ~ExoticBSEngine() {}

private:
    Wrapper<RandomBase> the_generator;
    MJArray drifts;
    MJArray standard_deviations;
    double log_spot;
    unsigned long number_of_times;
    MJArray variates;
};

#endif
