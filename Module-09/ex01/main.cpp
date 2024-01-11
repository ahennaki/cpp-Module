#include "RPN.hpp"

int main(int ac, char **av)
{    
    if (ac != 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    std::string input(av[1]);
    RPN rpn;

    std::cout << rpn.rpnOperation(input) << std::endl;
    return (0);
}