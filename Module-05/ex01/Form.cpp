#include "Form.hpp"

Form::Form() : name("") , signedIn(0) , gradeSgn(1) , gradeEx(1) {}

Form::Form(std::string name, bool signedIn, int gradeSgn, int gradeEx) : name(name) , signedIn(signedIn) , gradeSgn(gradeSgn) , gradeEx(gradeEx)
{
    if (gradeSgn < 1)
        throw Form::GradeTooHighException();
    if (gradeSgn > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& obj) : name(obj.name) , signedIn(obj.signedIn) , gradeSgn(obj.gradeSgn) , gradeEx(obj.gradeEx) {}

Form& Form::operator=(const Form& obj)
{
    if (this != &obj)
    {
        const_cast<std::string&>(name) = obj.name;
        signedIn = obj.signedIn;
        const_cast<int&>(gradeSgn) = obj.gradeSgn;
        const_cast<int&>(gradeEx) = obj.gradeEx;
    }
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
