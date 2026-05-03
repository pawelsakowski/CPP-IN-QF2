#include "path_dependent.h"

// constructor definition
PathDependent::PathDependent(const MJArray &look_at_times_)
    : look_at_times(look_at_times_)
{
}

// definition of the only one non-abstract method
const MJArray &PathDependent::get_look_at_times() const
{
    return look_at_times;
}
