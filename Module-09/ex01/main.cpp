#include "RPN.hpp"
#include <cstdlib>

int main(int ac, char **av)
{    
    if (ac != 2)
    {
        std::cerr << "Usage: ./RPN \" expression \"" << std::endl;
        return (EXIT_FAILURE);
    }
    std::string input(av[1]);
    RPN rpn;

    std::cout << rpn.rpnOperation(input) << std::endl;
    return (EXIT_SUCCESS);
}