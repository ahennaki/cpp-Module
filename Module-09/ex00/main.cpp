#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: \"./btc input.txt\"" << std::endl;
        return EXIT_FAILURE;
    }
    static_cast<void>(av);
    std::string filename("2009-01-14");
    // BitcoinExchange exchange;
    // std::cout << exchange.data["2009-01-14"] << std::endl;
    validDate(filename);
    return EXIT_SUCCESS;
}
