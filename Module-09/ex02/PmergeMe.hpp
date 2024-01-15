#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>

template <typename Container>
class PmergeMe 
{
    private:
        Container data;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& obj);
        PmergeMe& operator=(const PmergeMe& obj);
        ~PmergeMe();

        void sort();
};

bool checkArgs(int ac, char **av);


#endif
