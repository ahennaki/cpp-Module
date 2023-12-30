#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

int countOcc(const std::string& str, char c) {
    int count = 0;

    for (size_t i = 0; i < str.length(); i++)
        if (str[i] == c)
            count++;
    return count;
}

bool checkValid(const std::string& str, char c, bool i)
{
    if (i)
        return (countOcc(str, c) > 1 || (countOcc(str, c) == 1 && str.front() != c));
    return (countOcc(str, c) != 1 || str.front() == c || str.back() == c);
}

e_type isInt(const std::string& input)
{
    if (!input.empty() && input.find_first_not_of("+-0123456789") != std::string::npos)
        return NONE;
    if (checkValid(input, '+', 1) || checkValid(input, '-', 1))
        return NONE;
    return INT;
}

e_type isChar(const std::string& input)
{
    if (!input.empty() && input.length() == 1 && std::isprint(input[0]))
        return CHAR;
    return NONE;
}

e_type isDouble(const std::string& input)
{
    if (!input.compare("nan") || !input.compare("+inf") || !input.compare("-inf"))
        return LITERALS;
    if (input.empty() || (!input.empty() && input.find_first_not_of("+-0123456789.") != std::string::npos))
        return NONE;
    if (checkValid(input, '+', 1) || checkValid(input, '-', 1) || checkValid(input, '.', 0))
        return NONE;
    return DOUBLE;
}

e_type isFloat(const std::string& input)
{
    if (!input.compare("+inff") || !input.compare("-inff"))
        return LITERALS;
    if (input.empty() || (!input.empty() && input.find_first_not_of("+-0123456789.f") != std::string::npos))
        return NONE;
    if (checkValid(input, '+', 1) || checkValid(input, '-', 1) || checkValid(input, '.', 0))
        return NONE;
    if (countOcc(input, 'f') != 1 || !isdigit(input[input.length() - 2]) || input.back() != 'f')
        return NONE;
    return FLOAT;
}

e_type getType(const std::string& input)
{
    int type;

    type = isInt(input) + isChar(input) + isDouble(input) + isDouble(input);
    switch (type)
    {
    case 1:
        return INT;
        break;
    case 2:
        return CHAR;
        break;
    case 3:
        return DOUBLE;
        break;
    case 4:
        return FLOAT;
        break;
    case 5:
        return LITERALS;
        break;
    default:
        return NONE;
        break;
    }
}

void printInt(int i)
{
    if (i >= 0 && i <= 127 && !isprint(i))
        std::cout << "char: Non displayable" << std::endl;
    else if (i > 127 || i < 0)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void printChar(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void printLiterals(const std::string& input)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (input.compare("+inff"))
    {
        std::cout << "float: " << input << std::endl;
        std::cout << "double: +inf" << std::endl;
        return ;
    }
    else if (input.compare("-inff"))
    {
        std::cout << "float: " << input << std::endl;
        std::cout << "double: -inf" << std::endl;
        return ;
    }
    std::cout << "float: " << input << "f" << std::endl;
    std::cout << "double: " << input << std::endl;

}

void printFloat(float f)
{
    std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void printDouble(double d)
{
    std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
    e_type  type;

    type = getType(input);

    switch (type)
    {
        case INT:
            printInt(std::stoi(input));
            break;
        case CHAR:
            printChar(input[0]);
            break;
        case DOUBLE:
            printDouble(atof(input.c_str()));
            break;
        case FLOAT:
            printFloat(static_cast<float>(atof(input.c_str())));
            break;
        case LITERALS:
            printLiterals(input);
            break;
        default:
            std::cerr << "Invalide input!" << std::endl;
            break;
    }
}
