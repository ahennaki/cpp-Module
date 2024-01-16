#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>
#include <sstream>

template<typename Container>
class PmergeMe 
{
    private:
        Container data;
    public:
        PmergeMe();
        PmergeMe(Container& data);
        PmergeMe(const PmergeMe& obj);
        PmergeMe& operator=(const PmergeMe& obj);
        ~PmergeMe();

        Container& checkArgs(int ac, char **av);
        void sort();
};



#endif
