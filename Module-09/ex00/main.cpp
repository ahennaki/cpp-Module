#include "BitcoinExchange.hpp"
#include <string>

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: \"./btc input.txt\"" << std::endl;
        return EXIT_FAILURE;
    }
    std::string fileName(av[1]);
    std::string dataFile("data.csv");

    BitcoinExchange exchange(dataFile);
    exchange.btcExchange(fileName);
    return EXIT_SUCCESS;
}
