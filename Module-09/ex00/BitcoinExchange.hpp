#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

class BitcoinExchange
{
    // private:

    public:
        std::map<std::string, double> data;
        BitcoinExchange();
        ~BitcoinExchange();
        void btcExchange(const std::string &filename);

};

int     toInt(std::string& input);
double  toDouble(std::string& input);
bool    isNumber(std::string& input);
bool    validDate(std::string& date);

#endif
