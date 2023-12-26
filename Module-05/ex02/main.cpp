#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void )
{
    try
    {
        Bureaucrat brc("brc", 2);
        ShrubberyCreationForm form1("scf");
        RobotomyRequestForm form2("rrf");
        PresidentialPardonForm form3("ppf");

        std::cout << "--------------- (Shrubbery) ---------------" << std::endl;
        brc.signForm(form1);
        brc.executeForm(form1);
        std::cout << "--------------- (Robotomy) ---------------" << std::endl;
        brc.signForm(form2);
        brc.executeForm(form2);
        brc.executeForm(form2);
        brc.executeForm(form2);
        brc.executeForm(form2);
        std::cout << "--------------- (President) ---------------" << std::endl;
        brc.signForm(form3);
        brc.executeForm(form3);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}