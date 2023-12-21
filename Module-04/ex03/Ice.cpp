#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    // std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice(const Ice& obj)
{
    this->type = obj.type;
    // std::cout << "Ice Copy constructor called." << std::endl;
}

Ice &Ice::operator=(const Ice& obj)
{
    if (this != &obj)
        this->type = obj.type;
    // std::cout << "Ice Copy assignment operator called." << std::endl;
    return *this;
}

Ice::~Ice()
{
    // std::cout << "Ice destructor called." << std::endl;
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
