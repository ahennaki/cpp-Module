#include "PmergeMe.hpp"

int main(int ac, char **av)
{    
    if (ac < 2)
    {
        std::cerr << "Usage: ./PmergeMe <positive integer sequence>" << std::endl;
        return (EXIT_FAILURE);
    }
    if (!checkArgs(ac, av + 1))
    {
        std::cerr << "Error" << std::endl;
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
