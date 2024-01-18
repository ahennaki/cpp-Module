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
        int stglr;
    public:
        PmergeMe();
        PmergeMe(char **av);
        PmergeMe(const PmergeMe& obj);
        PmergeMe& operator=(const PmergeMe& obj);
        ~PmergeMe();

        size_t getSize() const;
        void printData() const;
        int binarySearch(int target);
        void sort();
};

void printTime(double time, size_t size, std::string str);

#endif
