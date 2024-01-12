#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

class BitcoinExchange
{
    private:
        std::map<std::string, double> data;
        std::string dataFile;

    public:
        BitcoinExchange();
        BitcoinExchange(std::string& dataFile);
        BitcoinExchange(const BitcoinExchange& obj);
        BitcoinExchange& operator=(const BitcoinExchange& obj);
        ~BitcoinExchange();
        void btcExchange(const std::string &filename);

};

int     toInt(std::string& input);
double  toDouble(std::string& input);
bool    isNumber(std::string& input);
bool    validDate(std::string& date);
bool    validNumber(std::string &value);
std::string previousDate(std::string& date);

#endif
