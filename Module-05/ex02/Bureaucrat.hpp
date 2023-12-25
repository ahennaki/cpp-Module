#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& obj);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& obj);

        const std::string& getName() const;
        const int& getGrade() const;

        void increment();
        void decrement();
        void signForm(AForm& form);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw() {return "Grade is too high!";}
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw() {return "Grade is too low!";}
        };
};

std::ostream& operator<<(std::ostream& out,const Bureaucrat& obj);

#endif
