#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cstdlib>
#include <string>
#include <variant>

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    std::string line;
    std::string date;
    std::string value;
    int i;

    if (!file.is_open() || file.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << "Error: data file does not exist or is empty!" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::getline(file, line);
    while (std::getline(file, line))
    {
        i = line.find(',');
        date = line.substr(0, i);
        value = line.substr(i + 1, line.length());
        data[date] = toDouble(value);
    }
    file.close();
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::btcExchange(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open() || file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Error: input file does not exist or is empty!" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::getline(file, line);
    if (line != "date | value") {
        std::cerr << "Error: invalid format!" << std::endl;
        exit(EXIT_FAILURE);
    }
    while (std::getline(file, line)) {

    }
}

int leapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 29;
    return 28;
}

bool validDate(std::string &date)
{
    std::string year;
    std::string month;
    std::string day;

    if (date[4] != '-' || date[7] != '-')
        return false;
    year = date.substr(0, 4);
    month = date.substr(5, 2);
    day = date.substr(8, 2);
    if (!isNumber(year) || !isNumber(month) || !isNumber(day))
        return false;

    int y = toInt(year);
    int m = toInt(month);
    int d = toInt(day);

    if (y < 2009 || y > 2022 || m > 12 || m < 1 || d > 31 || d < 1)
        return false;
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d == 31)
        return false;
    if (m == 2)
        if (d > leapYear(y))
            return false;
    return true;
}

bool isNumber(std::string &input)
{
    if (input.find_first_not_of("0123456789") != std::string::npos)
        return false;
    return true;
}

int toInt(std::string& input)
{
    try
    {
        /* code */
        int i;
        std::stringstream str(input);

        str >> i;
        return i;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

double toDouble(std::string& input)
{
    try
    {
        /* code */
        double d;
        std::stringstream str(input);

        str >> d;
        return d;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
