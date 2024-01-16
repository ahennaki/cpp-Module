#include "PmergeMe.hpp"
#include <climits>
#include <cstddef>
#include <utility>
#include <vector>

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

template<typename Container>
Container& checkArgs(int ac, char **av){
    Container ctr;
    int value;

    for (size_t i = 0; i < ac; i++)
    {
        std::string str(av[i]);
        if (str.empty() || str.find_first_not_of("+0123456789") != std::string::npos || checkPlus(str, '+'))
            return 0;
        value = toInt(str);
        if (value > INT_MAX)
            return 0;
        ctr.puch_back(value);
    }
    return ctr;
}

template<typename Container>
PmergeMe<Container>::PmergeMe() {}

template<typename Container>
PmergeMe<Container>::PmergeMe(Container& data) : data(data) {}

template<typename Container>
PmergeMe<Container>::~PmergeMe() {}

template<typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& obj) {
    data = obj.data;
}

template<typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe<Container>& obj){
    if (this != &obj)
        data = obj.data;
    return *this;
}

void sortPairs(std::vector <std::pair <int, int> > &vecPair) {
    
}

std::vector<int> generateIndex(size_t size) {
    std::vector<int> index;
    int jacobSthal[size + 1];
    int ljn = 2;

    jacobSthal[0] = 0;
    jacobSthal[1] = 1;
    for (size_t i = 2; index.size() < size; i++) {
        jacobSthal[i] = jacobSthal[i - 1] + 2 * jacobSthal[i - 2];
        if (i != 2)
            index.push_back(jacobSthal[i]);
        for (size_t j = jacobSthal[i] - 1; j > ljn; j--)
            index.push_back(j);
        ljn = jacobSthal[i];
    }
    return index;
}

template<typename Container>
void PmergeMe<Container>::sort() {
    if (data.size() <= 1)
        return;
    std::vector <std::pair <int, int> > vecPair;
    for (size_t i = 0; (i + 1) < data.size(); i += 2) {
        if (data[i] < data[i + 1])
            std::swap(data[i], data[i + 1]);
        vecPair.push_back(std::make_pair(data[i], data[i + 1]));
    }

    std::vector<int> indexes = generateIndex(data.size());
}
