#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

enum e_type
{
    NONE,
    INT,
    CHAR,
    DOUBLE,
    FLOAT,
    LITERALS
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
    public:
        static void convert(std::string& input);
};

#endif
