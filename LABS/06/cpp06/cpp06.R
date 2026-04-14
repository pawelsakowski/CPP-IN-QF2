# C++ in Quantitative Finance II
# cpp06
# Paweł Sakowski
# University of Warsaw

# 0 Loading packages ===========================================================
library(inline) # allows to use C++ inline - within R code
library(Rcpp) # Rccp package by Dirk Eddelbuettel
library(tidyverse)

# 1 Using cppFunction() ========================================================
cppFunction(
  "
  double ZeroCouponBondPrice(int n, double ytm, double f){
    double price = 0;
	  price += f/pow(1+ytm, double(n)) ;
	  return price;
  }
"
)

# call the function
ZeroCouponBondPrice(10, 0.1, 1000)

# build a wrapping function in R
ZeroCouponBondPrice1 <- function(r) {
  return(ZeroCouponBondPrice(10, r, 1000))
}

# call the R function
ZeroCouponBondPrice1(0.05)

# create a vector with argument values
ytm <- seq(0.001, 0.1, by = 0.001)

# call function for all argument values
sapply(ytm, ZeroCouponBondPrice1)
# or alternatively with the purrr package
ytm |> map_dbl(ZeroCouponBondPrice1)

# a simple plot
plot(ytm, sapply(ytm, ZeroCouponBondPrice1))

# same plot using ggplot2 package
tibble(
  x = ytm,
  y = map_dbl(ytm, ZeroCouponBondPrice1)
) |>
  ggplot(aes(x = x, y = y)) +
  geom_point(color = 'red') +
  labs(
    x = "yield to maturity",
    y = "price of zero-coupon bond",
    title = "zero-coupon bond price vs. yield to maturity"
  ) +
  theme_bw()


# 2 Pricing function for coupon bonds ==========================================
# Write and implement in R a similar function for coupon bonds.
# Build an R function based on that function and give it a name "BondPrice1',
# as it will be used in the next steps.

# 3 Comparing two relationships ================================================
bond_data <-
  tibble(
    ytm = ytm,
    bond1 = map_dbl(ytm, ZeroCouponBondPrice1),
    bond2 = map_dbl(ytm, BondPrice1)
  )

bond_data |>
  pivot_longer(-ytm) |>
  ggplot(aes(x = ytm, y = value, color = name)) +
  geom_point() +
  labs(
    title = "bond price vs. ytm",
    x = "yield to maturity",
    y = "price of a bond"
  ) +
  theme_bw()


# 4 Using sourceCpp() ==========================================================

# a) Compile c++ functions from external source files
# (function4a.cpp and function4b.cpp) using sourceCpp()

# b) call the functions

# 5 Measuring efficiency of MC simulations =====================================

# Example: approximation of the Pi value

mc_data <-
  tibble(
    x = runif(10000),
    y = runif(10000),
    r = sqrt(1 - x^2),
    d = sqrt(x^2 + y^2) < 1
  ) |>
  arrange(d)

mc_data |>
  ggplot(aes(x = x, y = y, color = d)) +
  geom_point(size = 0.1) +
  geom_line(aes(y = r), color = "darkgray") +
  coord_fixed(ratio = 1) +
  theme_bw()


## 5.1 An R function based on loop =============================================

piR1 <- function(N) {
  counter = 0
  for (i in 1:N) {
    x <- runif(1)
    y <- runif(1)
    d <- sqrt(x^2 + y^2)
    if (d <= 1) counter = counter + 1
  }
  return(4 * counter / N)
}

## 5.2 An R function based on vectors ==========================================

piR2 <- function(N) {
  x <- runif(N)
  y <- runif(N)
  d <- sqrt(x^2 + y^2)
  return(4 * sum(d <= 1.0) / N)
}

## 5.3 A C++ function based on loop ============================================

cppFunction(
  "
            double piCpp1(const int N) {
              RNGScope scope; // ensure RNG gets set/reset
              double x;
              double y;
              double d;
              int long counter;
            
              for(int i = 0; i < N; i++){
                x = ((double)rand()/(double)RAND_MAX);
                y = ((double)rand()/(double)RAND_MAX);
                d = sqrt(x * x + y * y);
                if (d <= 1) counter++;
              }
            
              return 4.0 * counter / N;
            
            }
            "
)

## 5.4 A C++ function based on vector ==========================================

cppFunction(
  "
  double piCpp2(const int N) {
    RNGScope scope; // ensure RNG gets set/reset
    NumericVector x = runif(N);
    NumericVector y = runif(N);
    NumericVector d = sqrt(x * x + y * y);
    
    return 4.0 * sum(d <= 1.0) / N;
  }
  "
)

## 5.5 Comparison ==============================================================
# install.packages("rbenchmark")
library(rbenchmark)
N <- 10000
set.seed(123)
benchmark(piR1(N), piR2(N), piCpp1(N), piCpp2(N), replications = 1000)[, 1:4]


# 6. Simple functions with rolling window ======================================
sourceCpp("LABS/06/cpp06/function6.cpp")

# draw increments (white noise)
wn <- rnorm(1000, mean = 0, sd = 0.1)

# transform increments to random-walk series
rw <- exp(get_cumsum(wn))

# merge vectors into a tibble
rwalk <- tibble(wn, rw)

# rename variables
rwalk <-
  rwalk |>
  rename(r = wn)

# add variable with current number of observation
rwalk <-
  rwalk |>
  mutate(obs = row_number())

# visualization
rwalk |>
  pivot_longer(-obs) |>
  ggplot(aes(x = obs, y = value, color = name)) +
  labs(
    x = "time",
    y = "",
    title = "Random walk and its increments",
    caption = "source: own simulation"
  ) +
  geom_line() +
  facet_grid(name ~ ., scales = "free")

# 7 Exercices ==================================================================

# Write in C++ and implement in R functions which return:

# a) simple moving average with given memory: SMA(x, k)

# b) exponentially weighted moving average with given memory: EWMA(x, k)

# c) moving window standard deviation with given memory: runningSD(x, k)

# d) moving window median with given memory: runningMedian(x,k)

# e) moving window quartile with given memory: runningQuartile(x, k, alpha)
