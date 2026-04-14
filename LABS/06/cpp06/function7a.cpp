#include <Rcpp.h>
#include <numeric> // for std::partial_sum

using namespace Rcpp;

// [[Rcpp::export]]
NumericVector get_sma(NumericVector x, int k){
  // initialize an accumulator variable
  double runningSum = 0;
  int threshold = 0;
  
  // initialize the result vector
  NumericVector result(x.size());
  
  for(int i = (x.size() - 1); i >= 0; i--){
    runningSum = 0;
    if (i < k) threshold = i+1;
    else threshold = k;
    for(int j = 0; j < threshold; j++) {
      runningSum += x[i-j];
      }
    result[i] = runningSum / threshold ; 
    }
    return result;
  }