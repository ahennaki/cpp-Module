#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string& dataFile)
{
    std::ifstream file(dataFile);
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
        value = line.substr(i + 1);
        data[date] = toDouble(value);
    }
    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {*this = obj;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
    if (this != &obj)
        data = obj.data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string ft_strtrim(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
        return str;
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

void BitcoinExchange::btcExchange(const std::string &fileName)
{
    std::ifstream file(fileName);
    std::string line;
    std::string date;
    std::string value;
    size_t i;

    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        exit(EXIT_FAILURE);
    }

    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Error: file is empty!" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::getline(file, line);
    if (line != "date | value") {
        std::cerr << "Error: invalid format!" << std::endl;
        exit(EXIT_FAILURE);
    }

    while (std::getline(file, line)) {
        i = line.find('|');

        if (i == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue ;
        }

        date = ft_strtrim(line.substr(0, i));
        if (!validDate(date)) {
            std::cerr << "Error: invalid date: '" << date << "'" << std::endl;
            continue ; 
        }

        value = ft_strtrim(line.substr(i + 1));
        if (!validNumber(value))
            continue ;

        std::map<std::string, double>::iterator it;
        std::string prevDate = date;

        it = data.find(date);
        while (it == data.end()) {
            std::string currentDate = prevDate;
            prevDate = previousDate(currentDate);
            it = data.find(prevDate);
        }

        std::cout << date << " => " << value  << " = "
            << it->second * toDouble(value) << std::endl;
    }
    file.close();
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

    if (date.empty() || date.length() != 10 || date[4] != '-' || date[7] != '-')
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

int countOcc(std::string& str, char c) {
    int count = 0;

    for (size_t i = 0; i < str.length(); i++)
        if (str[i] == c)
            count++;
    return count;
}

bool checkSign(std::string& str, char c) {
    return (countOcc(str, c) > 1 || (countOcc(str, c) == 1 && str.front() != c));
}

bool validNumber(std::string &value)
{
    if (value.empty() || value.find_first_not_of("+-0123456789.") != std::string::npos) {
        std::cerr << "Error: not a number." << std::endl;
        return false;
    }

    if ((value.length() == 1 && !isNumber(value)) || value.front() == '.'){
        std::cerr << "Error: not a number." << std::endl;
        return false;
    }

    if (countOcc(value, '.') > 1 || checkSign(value, '+') || checkSign(value, '-')) {
        std::cerr << "Error: not a number." << std::endl;
        return false;
    }

    if (toDouble(value) < 0){
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    if (toDouble(value) > 1000){
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}

bool isNumber(std::string &input)
{
    return (input.find_first_not_of("0123456789") == std::string::npos);
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

std::string toString(int value)
{
    try
    {
        std::stringstream str;

        str << value;

        return str.str();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

std::string previousDate(std::string& date)
{
    std::string syear = date.substr(0, 4);
    std::string smonth = date.substr(5, 2);
    std::string sday = date.substr(8, 2);

    int year = toInt(syear);
    int month = toInt(smonth);
    int day = toInt(sday);

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    daysInMonth[1] = leapYear(year);

    day--;
    if (day == 0) {
        month--;
        if (month == 0) {
            month = 12;
            year--;
        }
        day = daysInMonth[month - 1];
    }

    syear = toString(year);
    smonth = (month < 10) ? "0" + toString(month) : toString(month);
    sday = (day < 10) ? "0" + toString(day) : toString(day);

    return syear + "-" + smonth + "-" + sday;
}
