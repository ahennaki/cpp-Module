#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T *array;
        unsigned int size;
    public:
        Array() : array(new T[]) , size(0) {};
        Array(unsigned int n) : array(new T[n]) , size(n) {};
        Array(unsigned int n) : array(new T[n]) , size(n) {};
};

#endif
