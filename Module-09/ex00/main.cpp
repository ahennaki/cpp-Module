#include "BitcoinExchange.hpp"
#include <string>

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: \"./btc input.txt\"" << std::endl;
        return EXIT_FAILURE;
    }
    std::string filename(av[1]);
    BitcoinExchange exchange;
    exchange.btcExchange(filename);
    return EXIT_SUCCESS;
}
