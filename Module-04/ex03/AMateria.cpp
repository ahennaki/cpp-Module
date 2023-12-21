#include "AMateria.hpp"

AMateria::AMateria()
{
    this->type = "";
    // std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type)
{
    this->type = type;
    // std::cout << "AMateria constructor called." << std::endl;
}

AMateria::AMateria(const AMateria& obj)
{
    this->type = obj.type;
    // std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria &AMateria::operator=(const AMateria& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    // std::cout << "AMaeria Copy assignment operator called." << std::endl;
    return (*this);
}

AMateria::~AMateria()
{
    // std::cout << "AMateria destructor called." << std::endl;
}

std::string const &AMateria::getType() const
{
    // std::cout << "AMateria getType called." << std::endl;
    return (type);
}

AMateria* AMateria::clone() const
{
    return (AMateria*)this;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria " << type << " used on " << target.getName() << std::endl;
}
