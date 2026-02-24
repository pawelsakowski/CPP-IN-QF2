#ifndef PAYOFF2_H
#define PAYOFF2_H

class PayOff
{
public:
    PayOff() = default;
    virtual double operator()(double spot) const = 0;
    virtual ~PayOff() = default;
};

class PayOffCall : public PayOff
{
public:
    PayOffCall(double strike);
    double operator()(double spot) const override;

private:
    double strike;
};

class PayOffPut : public PayOff
{
public:
    PayOffPut(double strike);
    double operator()(double spot) const override;

private:
    double strike;
};

#endif