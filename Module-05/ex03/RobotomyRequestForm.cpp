#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RRF", 72, 45) , target("RRFT") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RRF", 72, 45) , target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rrf) : AForm(rrf) , target(rrf.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rrf)
{
    if (this != &rrf)
        target = rrf.target;
    return (*this);
}

void RobotomyRequestForm::actionForm() const
{
    static int i;

    if (!(i % 2))
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << target << " failed the robotomy." << std::endl;
    i++;
}
