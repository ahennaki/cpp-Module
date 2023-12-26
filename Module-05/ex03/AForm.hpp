#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool signedIn;
        const int gradeSgn;
        const int gradeEx;
    public:
        AForm();
        AForm(std::string name, int gradeSgn, int gradeEx);
        AForm(const AForm& obj);
        AForm& operator=(const AForm& obj);
        virtual ~AForm();

        const std::string& getName() const;
        const bool& getSigned() const; 
        const int& getGradeSng() const; 
        const int& getGradeEx() const;

        void beSigned(const Bureaucrat& brc);
        void execute(Bureaucrat const & executor) const;

        virtual void actionForm() const = 0;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out,const AForm& obj);

#endif
