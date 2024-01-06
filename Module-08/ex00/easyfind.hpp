#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
void easyfind(T& ctr, int value)
{
    if (std::find(ctr.begin(), ctr.end(), value) != ctr.end())
        std::cout << "Value found." << std::endl;
    else
        std::cerr << "Value not found." << std::endl;
}

#endif
