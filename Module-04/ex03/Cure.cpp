#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    // std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure(const Cure& obj)
{
    this->type = obj.type;
    // std::cout << "Cure Copy constructor called." << std::endl;
}

Cure &Cure::operator=(const Cure& obj)
{
    if (this != &obj)
        this->type = obj.type;
    // std::cout << "Cure Copy assignment operator called." << std::endl;
    return *this;
}

Cure::~Cure()
{
    // std::cout << "Cure destructor called." << std::endl;
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
