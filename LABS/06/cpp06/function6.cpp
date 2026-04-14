#include <Rcpp.h>
#include <numeric> // for std::partial_sum

using namespace Rcpp;

// [[Rcpp::export]]
NumericVector get_cumsum(NumericVector x){
  // initialize an accumulator variable
  double running_sum = 0;
  
  // initialize the result vector
  NumericVector result(x.size());
  
  for(int i = 0; i < x.size(); i++){
    running_sum += x[i];
    result[i] = running_sum;
    }
    
    return result;
  }