#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool signedIn;
        const int gradeSgn;
        const int gradeEx;
    public:
        Form();
        Form(std::string name, bool signedIn, int gradeSgn, int gradeEx);
        Form(const Form& obj);
        Form& operator=(const Form& obj);
        ~Form();

        const std::string& getName() const;
        const bool& getSigned() const; 
        const int& getGradeSng() const; 
        const int& getGradeEx() const;

        void beSigned(const Bureaucrat& brc);

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

std::ostream& operator<<(std::ostream& out,const Form& obj);

#endif
