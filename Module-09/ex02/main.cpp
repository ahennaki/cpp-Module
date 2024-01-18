#include "PmergeMe.hpp"

int main(int ac, char **av)
{    
    if (ac < 2)
    {
        std::cerr << "Usage: ./PmergeMe <positive integer sequence>" << std::endl;
        return (EXIT_FAILURE);
    }
    try {
        PmergeMe<std::vector<int> > vector(av + 1);
        PmergeMe<std::deque<int> > deque(av + 1);
        std::cout << "Before:   ";
        vector.printData();

        std::clock_t start = std::clock();
        vector.sort();
        double time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
        std::cout << "After:    ";
        vector.printData();
        printTime(time, vector.getSize(), "vector");

        start = std::clock();
        deque.sort();
        time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
        printTime(time, deque.getSize(), "deque");

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return (EXIT_SUCCESS);
}
