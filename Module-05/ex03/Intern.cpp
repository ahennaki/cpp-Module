#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& obj)
{
    *this = obj;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& obj)
{
    ( void ) obj;
    return (*this);
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::string	forms[3] = {"shrubbery creation" , "presidential pardon", "robotomy request"};
	size_t i;

	for (i = 0; i < 3; i++)
	{
		if (name == forms[i])
			break ;
	}
	switch (i)
	{
	    case 0:
	    	std::cout << "Intern creates " << name << "." << std::endl;
	    	return (new ShrubberyCreationForm(target));
	    	break;
	    case 1:
	    	std::cout << "Intern creates " << name << "." << std::endl;
	    	return (new PresidentialPardonForm(target));
	    	break;
	    case 2:
	    	std::cout << "Intern creates " << name << "." << std::endl;
	    	return (new RobotomyRequestForm(target));
	    	break;
	    default:
	    	std::cout << "Intern cannot create " << name << "!!" << std::endl;
	    	return (0);
	    	break;
	}
}