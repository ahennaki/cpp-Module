#include "PmergeMe.hpp"
#include <climits>
#include <cstddef>

int countOcc(std::string& str, char c) {
    int count = 0;

    for (size_t i = 0; i < str.length(); i++)
        if (str[i] == c)
            count++;
    return count;
}

bool checkPlus(std::string& str, char c) {
    return (countOcc(str, c) > 1 || (countOcc(str, c) == 1 && str.front() != c));
}

long long toInt(std::string& input)
{
    try
    {
        /* code */
        long long i;
        std::stringstream str(input);

        str >> i;
        return i;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

bool checkArgs(int ac, char **av)
{
    for (size_t i = 0; i < ac; i++)
    {
        std::string str(av[i]);
        if (str.empty() || str.find_first_not_of("+0123456789") != std::string::npos || checkPlus(str, '+'))
            return false;
        if (toInt(str) > INT_MAX)
            return false;
    }
    return true;
}

template <typename Container>
PmergeMe<Container>::PmergeMe() {}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& obj) {
    data = obj.data;
}

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe& obj){
    if (this != &obj)
        data = obj.data;
    return *this;
}
