#include "RPN.hpp"
#include <cstddef>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& obj) {*this = obj;}

RPN& RPN::operator=(const RPN& obj)
{
    if (this != &obj)
        stack = obj.stack;
    return *this;
}

RPN::~RPN() {}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool validInput(std::string& str)
{
    int digit = 0;
    int oper = 0;

    if (str.find_first_not_of("0123456789+-/* ") != std::string::npos)
        return false;
    for(size_t i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
            digit ++;
        else if (isOperator(str[i]))
            oper++;
    }
    if (oper != digit  - 1)
        return false;
    return true;
}

bool RPN::operation(char c)
{
    long long nb;

    nb = stack.top();
    if (c == '/' && nb == 0)
        return false;
    stack.pop();
    switch (c)
    {
        case '+':
            stack.top() += nb;
            break;
        case '-':
            stack.top() -= nb;
            break;
        case '*':
            stack.top() *= nb;
            break;
        case '/':
            stack.top() /= nb;
            break;
    }
    return true;
}

long long RPN::rpnOperation(std::string& str)
{
    if (!validInput(str))
    {
        std::cerr << "Error" << std::endl;
        exit(EXIT_FAILURE);
    }
    for(size_t i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
            stack.push(str[i] - '0');
        if (isOperator(str[i]) && stack.size() > 1)
            if (!operation(str[i]))
                break ;
    }
    if (stack.size() > 1)
    {
        std::cerr << "Error" << std::endl;
        exit(EXIT_FAILURE);
    }
    return (stack.top());
}
