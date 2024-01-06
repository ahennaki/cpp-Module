#include "Span.hpp"

const char *Span::OutOfRange::what() const throw() 
{
    return "Out of range!";
}

const char *Span::NotFound::what() const throw() 
{
    return "No span can be found!";
}

Span::Span() {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span& obj)
{
    N = obj.N;
    vector = obj.vector;
}

Span::~Span() {}

Span& Span::operator=(const Span& obj)
{
    if (this != &obj)
    {
        N = obj.N;
        vector = obj.vector;
    }
    return *this;
}

void Span::addNumber(int nbr)
{
    if (vector.size() >= N)
        throw Span::OutOfRange();
    vector.push_back(nbr);
}

int Span::shortestSpan()
{
    if (vector.size() <= 1)
        throw Span::NotFound();
    std::vector<int> vec = vector;
    std::sort(vec.begin(), vec.end());
    std::vector<int>::iterator it = vec.begin();
    int min = INT_MAX;
    while (++it != vec.end())
        if (std::abs(*(it) - *(it - 1)) < min)
            min = std::abs(*(it) - *(it - 1));
    return min;
}

int Span::longestSpan()
{
    if (vector.size() <= 1)
        throw Span::NotFound();
    return (*std::max_element(vector.begin(), vector.end()) - *std::min_element(vector.begin(), vector.end()));
}

void Span::fillSpan(std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd)
{
    if (vector.size() >= N)
        throw Span::OutOfRange();
    vector.insert(vector.end(), itBegin, itEnd);
}
