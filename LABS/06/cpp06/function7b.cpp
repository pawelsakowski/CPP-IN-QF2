#include <Rcpp.h>
#include <numeric> // for std::partial_sum

using namespace Rcpp;

// [[Rcpp::export]]
NumericVector get_ewma(NumericVector x, double k){

  // initialize the result vector
  NumericVector ewma(x.size()+1);
  
  // first smoothed value equals to frist observed value
  ewma[0] = x[0];
  
  // main loop
  for(int i = 1; i < ewma.size(); i++){  
    ewma[i] = k*x[i-1] + (1-k)*ewma[i-1]; 
    }
   
   return ewma;
  
  }