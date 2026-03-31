library(tidyverse)

dt1 <-
  tibble(x = seq(-5, 5, 0.001)) |>
  mutate(cdf = pnorm(x)) |>
  glimpse()

dt1 |>
  ggplot(aes(x, cdf)) +
  geom_line()


dt2 <-
  tibble(x = seq(0, 1, 0.001)) |>
  mutate(icdf = qnorm(x))

dt2 |>
  ggplot(aes(x, icdf)) +
  geom_line()

dt3 <-
  tibble(x = seq(-5, 5, 0.001)) |>
  mutate(cdf = pnorm(x)) |>
  mutate(icdf = qnorm(x))

dt3 |>
  pivot_longer(!x) |>
  ggplot(aes(x, value, color = name)) +
  geom_line() +
  xlim(-2, 2) +
  ylim(-2, 2) +
  geom_hline(yintercept = c(0), col = "gray20") +
  geom_vline(xintercept = c(0), col = "gray20") +
  geom_hline(yintercept = c(1), col = "gray80") +
  geom_vline(xintercept = c(1), col = "gray80") +
  labs(
    x = "",
    y = "",
    title = "CDF and inverse CDF",
    subtitle = "for standard normal distribution"
  ) +
  theme(legend.title = element_blank())
