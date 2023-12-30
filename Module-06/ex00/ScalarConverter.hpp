#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

enum e_type
{
    NONE,
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    LITERALS
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
    public:
        static void convert(const std::string& input);
};

#endif
