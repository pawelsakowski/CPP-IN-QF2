#ifndef PATH_DEPENDENT_H
#define PATH_DEPENDENT_H

#include <vector>
#include "arrays.h"

// this is an auxiliary class
class CashFlow
{
public:
    double amount;
    unsigned long time_index;

    // constructor, 0UL stands for 'zero unsigned long'
    CashFlow(unsigned long time_index_ = 0UL, double amount_ = 0.0)
        : time_index(time_index_), amount(amount_) {};
};

class PathDependent
{
public:
    // constructor takes one array
    PathDependent(const MJArray &look_at_times_);

    const MJArray &get_look_at_times() const;

    // four abstracts methods
    virtual unsigned long max_number_of_cash_flows() const = 0;
    virtual MJArray possible_cash_flow_times() const = 0;
    virtual unsigned long cash_flows(const MJArray &spot_values,
                                     std::vector<CashFlow> &generated_flows)
        const = 0;
    virtual PathDependent *clone() const = 0;

    virtual ~PathDependent() {}

private:
    MJArray look_at_times;
};

#endif
