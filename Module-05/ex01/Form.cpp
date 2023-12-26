#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw() 
{
    return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() 
{
    return "Grade is too low!";
}

Form::Form() : name("") , signedIn(0) , gradeSgn(1) , gradeEx(1) {}

Form::Form(std::string name, int gradeSgn, int gradeEx) : name(name) , signedIn(0) , gradeSgn(gradeSgn) , gradeEx(gradeEx)
{
    if (gradeSgn < 1 || gradeEx < 1)
        throw Form::GradeTooHighException();
    if (gradeSgn > 150 || gradeEx > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& obj) : name(obj.name) , signedIn(obj.signedIn) , gradeSgn(obj.gradeSgn) , gradeEx(obj.gradeEx) {}

Form& Form::operator=(const Form& obj)
{
    if (this != &obj)
        signedIn = obj.signedIn;
    return (*this);
}

Form::~Form() {}

const std::string& Form::getName() const
{
    return name;
}

const bool& Form::getSigned() const
{
    return signedIn;
}

const int& Form::getGradeSng() const
{
    return gradeSgn;
}

const int& Form::getGradeEx() const
{
    return gradeEx;
}

void Form::beSigned(const Bureaucrat& brc)
{
    if (brc.getGrade() > gradeSgn)
        throw Form::GradeTooLowException();
    signedIn = 1;
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
    out << "Form name: " << obj.getName() << std::endl
    << "grade required to sign: " << obj.getGradeSng() << std::endl
    << "grade required to execute: " << obj.getGradeEx() << std::endl;
    if (obj.getSigned())
        out << "Signed: TRUE";
    else
        out << "Signed: FALSE";
    return out;
}
