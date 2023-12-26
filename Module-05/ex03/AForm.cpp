#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() 
{
    return "Grade is too low!";
}

AForm::AForm() : name("") , signedIn(0) , gradeSgn(1) , gradeEx(1) {}

AForm::AForm(std::string name, int gradeSgn, int gradeEx) : name(name) , signedIn(0) , gradeSgn(gradeSgn) , gradeEx(gradeEx)
{
    if (gradeSgn < 1 || gradeEx < 1)
        throw AForm::GradeTooHighException();
    if (gradeSgn > 150 || gradeEx > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& obj) : name(obj.name) , signedIn(obj.signedIn) , gradeSgn(obj.gradeSgn) , gradeEx(obj.gradeEx) {}

AForm& AForm::operator=(const AForm& obj)
{
    if (this != &obj)
        signedIn = obj.signedIn;
    return (*this);
}

AForm::~AForm() {}

const std::string& AForm::getName() const
{
    return name;
}

const bool& AForm::getSigned() const
{
    return signedIn;
}

const int& AForm::getGradeSng() const
{
    return gradeSgn;
}

const int& AForm::getGradeEx() const
{
    return gradeEx;
}

void AForm::beSigned(const Bureaucrat& brc)
{
    if (brc.getGrade() > gradeSgn)
        throw AForm::GradeTooLowException();
    signedIn = 1;
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
    out << "AForm name: " << obj.getName() << std::endl
    << "grade required to sign: " << obj.getGradeSng() << std::endl
    << "grade required to execute: " << obj.getGradeEx() << std::endl;
    if (obj.getSigned())
        out << "Signed: TRUE";
    else
        out << "Signed: FALSE";
    return out;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > gradeSgn)
        throw AForm::GradeTooLowException();
    this->actionForm();
}
