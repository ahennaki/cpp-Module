#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error" << std::endl;
        return 0;
    }
    // if (!invalideInput(av[1]))
    //     std::cout << "invalid input!!" << std::endl;
    // else
    //     std::cout << "all clear." << std::endl;
    ScalarConverter::convert(av[1]);

    return 0;
}
