#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        // sp.addNumber(11);
        std::cout << "Longest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Shortest span: " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::vector<int>    vec(100000);
        std::srand(time(NULL));
        std::generate(vec.begin(), vec.end(), std::rand);

        Span sp(vec.size());

        sp.fillSpan(vec.begin(), vec.end());

        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl; 
    }
    
    return 0;
}