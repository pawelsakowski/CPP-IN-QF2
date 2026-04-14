# cpp07
# Paweł Sakowski
# University of Warsaw

library(tidyverse)
library(ggplot2)

# 1. remove package if it exists
remove.packages("OptionPricer")
detach("package:OptionPricer", unload = TRUE) # if it still is in memory

# 2. install package and load to memory

# from binaries (no need to rebuild)
install.packages(
  "../OptionPricer_1.0_R_x86_64-pc-linux-gnu.tar.gz",
  type = "binaries",
  repos = NULL
)
# or from source (rebuilt automatically)
install.packages("../OptionPricer_1.0.tar.gz", type = "source", repos = NULL)
# load to memory
library("OptionPricer")

# 3. Call the function
MCEuropeanOptionPricer(0.5, 100, 95, 0.2, 0.06, 10000, 0)

# 4. build an R function: option price vs. time to maturity
MCEuropeanCall <- function(expiry) {
  return(
    MCEuropeanOptionPricer(expiry, 100, 95, 0.2, 0.06, 10000, 0)
  )
}

# 5. call the function
MCEuropeanCall(0.5)

# 6. arguments values of values of cunction
expiry <- seq(0.0001, 0.1, by = 0.001)
result <- sapply(expiry, MCEuropeanCall)

# 7. same plot using ggplot2 package

tibble(expiry, result) %>%
  ggplot(aes(x = expiry, y = result, col = "red")) +
  geom_line() +
  geom_point(size = 2, shape = 21, fill = "white") +
  labs(
    title = "price of European call option vs. time  to maturity",
    x = "time to maturity",
    y = "price of European call option"
  )

# 8. build an R function: option price vs. number of loops
MCEuropeanCallLoops <- function(loops) {
  return(
    MCEuropeanOptionPricer(0.5, 100, 95, 0.2, 0.06, loops, 0)
  )
}

MCEuropeanCallLoops(500)
loops <- 2^(1:25)
result <- sapply(loops, MCEuropeanCallLoops)

tibble(loops, result) %>%
  ggplot(aes(x = as.factor(loops), y = result)) +
  geom_point() +
  labs(
    x = "number of loops",
    y = "price of European call option",
    title = "price of European call option vs. number of loops"
  ) +
  theme(axis.text.x = element_text(angle = 90))

# 9. build an R function: option price vs. spot and volatility
MCEuropeanCallSpotVol <- function(spot, vol) {
  return(
    MCEuropeanOptionPricer(0.5, 100, spot, vol, 0.06, 100000, 0)
  )
}
# call function once
MCEuropeanCallSpotVol(100, 0.2)

# sequences of argument values
spot <- seq(90, 105, by = 0.5)
vol <- c(0.001, 0.01, 0.02, 0.05, 0.1, 0.15, 0.2, 0.3, 0.5, 1)

grid <- expand.grid(spot = spot, vol = vol)
result <- mapply(MCEuropeanCallSpotVol, spot = grid$spot, vol = grid$vol)
result.df <- data.frame(grid, result)
result.df

ggplot(data = result.df, aes(x = spot, y = result, group = vol, colour = vol)) +
  geom_line() +
  geom_point(size = 2, shape = 21, fill = "white") +
  labs(
    title = "price of European call option vs. spot price and volatility",
    x = "spot price",
    y = "price of European call option"
  )
