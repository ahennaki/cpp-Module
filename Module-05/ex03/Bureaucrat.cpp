#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Grade is too low!";
}

Bureaucrat::Bureaucrat() :  name("") , grade(1) {}

Bureaucrat::Bureaucrat(std::string name, int grade) :  name(name) , grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name) , grade(obj.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
    if (this != &obj)
        grade = obj.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const int& Bureaucrat::getGrade() const
{
    return grade;
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

void Bureaucrat::increment()
{
    if (grade == 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::decrement()
{
    if (grade == 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return out;
}

void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (AForm::GradeTooLowException &e)
    {
        std::cout << name << " coulnd't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch(AForm::GradeTooLowException& e)
    {
        std::cout << name << " coulnd't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}
