#include "RPN.hpp"

int main(int ac, char **av)
{    
    if (ac != 2)
    {
        std::cerr << "Usage: ./RPN \" <expression: 'digits and operators delimited by spaces'> \"" << std::endl;
        return (EXIT_FAILURE);
    }
    std::string input(av[1]);
    RPN rpn;

    std::cout << rpn.rpnOperation(input) << std::endl;
    return (EXIT_SUCCESS);
}