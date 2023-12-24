#include "Bureaucrat.hpp"

int main( void )
{
    try {
        Bureaucrat bureaucrat("high", 1);
        std::cout << bureaucrat << std::endl;

        // bureaucrat.increment();
        bureaucrat.decrement();
        
        std::cout << bureaucrat << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat("low", 150);
        std::cout << bureaucrat << std::endl;

        bureaucrat.increment();
        // bureaucrat.decrement();
        
        std::cout << bureaucrat << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}