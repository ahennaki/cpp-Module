#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    try
    {
        /* code */
        if (ac != 2)
        {
            std::cout << "Error" << std::endl;
            return 1;
        }
        std::string input(av[1]);
        ScalarConverter::convert(input);
    }
    catch(...)
    {
        std::cerr << "Error: exception" << std::endl;
    }
    
    // std::cout << static_cast<double>(av[1][0]) << std::endl;
    return 0;
}
