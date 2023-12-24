#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :  name("") , grade(1) {}

Bureaucrat::Bureaucrat(std::string name, int grade) :  name(name) , grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name)
{
    grade = obj.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
    if (this != &obj)
    {
        grade = obj.grade;
        const_cast<std::string&>(name) = obj.name;
    }
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
