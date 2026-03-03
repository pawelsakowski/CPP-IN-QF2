// PayOff.h

#ifndef PAYOFF3_H
#define PAYOFF3_H

// declaration of a base class
class PayOff
{
public:
	// construtor
	PayOff() {};
	// method (function)
	virtual double operator()(double spot) const = 0;
	// destructor
	virtual ~PayOff() {}

private:
};

// declaration of the first inherited class
class PayOffCall : public PayOff
{
public:
	// construtor
	PayOffCall(double strike_);
	// method (function)
	virtual double operator()(double spot) const;
	// destructor
	virtual ~PayOffCall() {}

private:
	// member (attribute)
	double strike;
};

// declaration of the second inherited class
class PayOffPut : public PayOff
{
public:
	// construtor
	PayOffPut(double strike_);
	// method (function)
	virtual double operator()(double spot) const;
	// destructor
	virtual ~PayOffPut() {}

private:
	// member (attribute)
	double strike;
};

#endif
