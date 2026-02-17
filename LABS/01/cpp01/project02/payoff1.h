// payoff1.h

#ifndef PAYOFF1_H
#define PAYOFF1_H

class Payoff
{

public:
    enum OptionType
    {
        Call,
        Put
    };

    Payoff(double strike, OptionType option_type);

    double operator()(double spot) const;

private:
    double strike_;
    OptionType option_type_;
};

#endif
