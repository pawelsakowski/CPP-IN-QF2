// normdist.cc 
// author: Bernt A Oedegaard
// numerical approximations to univariate N(z) and bivariate N(a,b,rho) 
// normal distributions

#include <math.h>     // math functions.

#ifndef PI 
#define PI 3.141592653589793238462643 
#endif 

double n(double z) {  // normal distribution function    
    return (1.0/sqrt(2*PI))*exp(-0.5*z);
};

// cumulative univariate normal distribution.
// This is a numerical approximation to the normal distribution.  
// See Abramowitz and Stegun: Handbook of Mathemathical functions
// for description.  The arguments to the functions are assumed 
// normalized to a (0,1 ) distribution. 

double N(double z) {
    double b1 =  0.31938153; 
    double b2 = -0.356563782; 
    double b3 =  1.781477937;
    double b4 = -1.821255978;
    double b5 =  1.330274429; 
    double p  =  0.2316419; 
    double c2 =  0.3989423; 

    if (z >  6.0) { return 1.0; }; // this guards against overflow 
    if (z < -6.0) { return 0.0; };
    double a=fabs(z); 
    double t = 1.0/(1.0+a*p); 
    double b = c2*exp((-z)*(z/2.0)); 
    double n = ((((b5*t+b4)*t+b3)*t+b2)*t+b1)*t; 
    n = 1.0-b*n; 
    if ( z < 0.0 ) n = 1.0 - n; 
    return n; 
}

// Numerical approximation to the bivariate normal distribution, 
//  as described e.g. in Hulls book

inline double f(double x, double y, double aprime, double bprime, double rho) {
    double r = aprime*(2*x-aprime) + bprime*(2*y-bprime)
        + 2 * rho * (x-aprime) * (y-bprime);
    return exp(r);
};

inline double sgn( double x) {  // sign function
    if (x>=0.0)  return 1.0;
    return -1.0;
};

double N(double a, double b, double rho) {
    if ( (a<=0.0) && (b<=0.0) && (rho<=0.0) ) { 
        double aprime = a/sqrt(2.0*(1.0-rho*rho));
        double bprime = b/sqrt(2.0*(1.0-rho*rho));
        double A[4]={0.3253030, 0.4211071, 0.1334425, 0.006374323}; 
        double B[4]={0.1337764, 0.6243247, 1.3425378, 2.2626645  };
        double sum = 0;
        for (int i=0;i<4;i++) {
            for (int j=0; j<4; j++) {
                sum += A[i]*A[j]* f(B[i],B[j],aprime,bprime,rho);
            };
        };
        sum = sum * ( sqrt(1.0-rho*rho)/PI);
        return sum;
    }
    else  if ( a * b * rho <= 0.0 ) {
        if ( ( a<=0.0 ) && ( b>=0.0 ) && (rho>=0.0) ) {
            return N(a) - N(a, -b, -rho); 
        }
        else if ( (a>=0.0) && (b<=0.0) && (rho>=0.0) ) {
            return N(b) - N(-a, b, -rho); 
        }
        else if ( (a>=0.0) && (b>=0.0) && (rho<=0.0) ) {
            return N(a) + N(b) - 1.0 + N(-a, -b, rho); 
        };
    }
    else  if ( a * b * rho >= 0.0 ) {
        double denum = sqrt(a*a - 2*rho*a*b + b*b);
        double rho1 = ((rho * a - b) * sgn(a))/denum;
        double rho2 = ((rho * b - a) * sgn(b))/denum;
        double delta=(1.0-sgn(a)*sgn(b))/4.0;
        return N(a,0.0,rho1) + N(b,0.0,rho2) - delta;
    };
    return -99.9; // should never get here
};


