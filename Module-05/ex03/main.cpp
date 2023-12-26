#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

// void f(){system("leaks Bureaucrat");}

int main( void )
{
    // atexit(f);
    {
        Intern  someRandomIntern;
        AForm*   rrf;

        rrf = someRandomIntern.makeForm("robotomy", "Bender");
        // rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        // rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        // rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        delete rrf;
    }

    return 0;
}