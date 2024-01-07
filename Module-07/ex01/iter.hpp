#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *Array, size_t len, void (*f)(T &))
{
    for (size_t i = 0; i < len; i++)
        f(Array[i]);
}

template <typename T>
void iter(T const *Array, size_t len, void (*f)(T const &))
{
    for (size_t i = 0; i < len; i++)
        f(Array[i]);
}

#endif
