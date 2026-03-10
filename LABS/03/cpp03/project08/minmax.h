// MinMax.h

#ifndef MINMAX_H
#define MINMAX_H

template <class T>
const T &max(const T &a, const T &b)
{
    return (a < b) ? b : a;
}

template <class T>
const T &min(const T &a, const T &b)
{
    return (a > b) ? b : a;
}
#endif
