#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PPF", 25, 5) , target("PPFT") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPF", 25, 5) , target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ppf) : AForm(ppf) , target(ppf.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ppf)
{
    if (this != &ppf)
        target = ppf.target;
    return (*this);
}

void PresidentialPardonForm::actionForm() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
