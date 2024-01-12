#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>

class RPN
{
    private:
        std::stack<long long> stack;

    public:
        RPN();
        RPN(const RPN& obj);
        RPN& operator=(const RPN& obj);
        ~RPN();

        bool operation(char c);

        long long rpnOperation(std::string& str);
};

#endif
