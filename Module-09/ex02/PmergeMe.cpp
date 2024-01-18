#include "PmergeMe.hpp"

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
PmergeMe<Container>::PmergeMe() {stglr = -1;}

template<typename Container>
PmergeMe<Container>::PmergeMe(char **av) : data() , stglr(-1) {
    long long value;

    for (size_t i = 0; av[i]; i++)
    {
        std::string str(av[i]);
        if (str.empty() || str.find_first_not_of("+0123456789") != std::string::npos || checkPlus(str, '+'))
            throw std::invalid_argument("Error");
        value = toInt(str);
        if (value > INT_MAX)
            throw std::invalid_argument("Error");
        data.push_back(value);
    }
}

template<typename Container>
PmergeMe<Container>::~PmergeMe() {}

template<typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& obj) {
    data = obj.data;
    stglr = obj.stglr;
}

template<typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe<Container>& obj){
    if (this != &obj)
    {
        data = obj.data;
        stglr = obj.stglr;
    }
    return *this;
}

template<typename Container>
size_t PmergeMe<Container>::getSize() const{return data.size();}

template<typename Container>
void PmergeMe<Container>::printData() const {
    for (size_t i = 0; i < data.size(); i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

void printTime(double time, size_t size, std::string str){
    std::cout
            <<	"Time to process a range of " << size
            << " elements with std::" << str << "<int>"
            << " : " << std::fixed << std::setprecision(5) << time << " us"
            << std::endl;
}

void sortPairs(std::vector <std::pair <int, int> > &vecPair) {
    if (vecPair.size() <= 1) {
        return; // Base case: Nothing to sort
    }

    // Divide the vector into two halves
    size_t middle = vecPair.size() / 2;
    std::vector <std::pair <int, int> > leftPair(vecPair.begin(), vecPair.begin() + middle);
    std::vector <std::pair <int, int> > rightPair(vecPair.begin() + middle, vecPair.end());

    // Recursively sort the two halves
    sortPairs(leftPair);
    sortPairs(rightPair);

    // Merge the sorted halves
    size_t leftIdx = 0;
    size_t rightIdx = 0;
    size_t idx = 0;

    while (leftIdx < leftPair.size() && rightIdx < rightPair.size()) {
        if (leftPair[leftIdx].first < rightPair[rightIdx].first)
            vecPair[idx++] = leftPair[leftIdx++];
        else
            vecPair[idx++] = rightPair[rightIdx++];
    }

    while (leftIdx < leftPair.size())
        vecPair[idx++] = leftPair[leftIdx++];

    while (rightIdx < rightPair.size())
        vecPair[idx++] = rightPair[rightIdx++];
}

std::vector<int> generateIndex(size_t size) {
    std::vector<int> index;
    int jacobSthal[size + 1];
    size_t ljn = 2;

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
int PmergeMe<Container>::binarySearch(int target) {
    int left = 0;
    int right = data.size() - 1;

    while (left <= right) {
        int middle = (left + right) / 2;

        if (data[middle] == target)
            return middle;
        else if (data[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return left;
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

    sortPairs(vecPair);
    std::vector<int> index = generateIndex(data.size());

    if (data.size() % 2)
        stglr = data.back();
    data.clear();
    data.push_back(vecPair[0].second);

    for (size_t i = 0; i < vecPair.size(); i++)
        data.push_back(vecPair[i].first);

    for (size_t i = 0; i < index.size(); i++) {
        size_t j = index[i] - 1;
        if (j >= vecPair.size())
            continue;
        int idx = binarySearch(vecPair[j].second);
        data.insert(data.begin() + idx, vecPair[j].second);
    }

    if (stglr != -1) {
        int idx = binarySearch(stglr);
        data.insert(data.begin() + idx, stglr);
    }
}

template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;
