#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
    public:
        static void convert(const std::string& input);
};

#endif
