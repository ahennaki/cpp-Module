#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
    private:
        unsigned int N;
        std::vector<int> vector;
 
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& obj);
        ~Span();
        Span& operator=(const Span& obj);

        void addNumber(int nbr);
        int shortestSpan();
        int longestSpan();

        void fillSpan(std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd);

        class OutOfRange : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class NotFound : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
