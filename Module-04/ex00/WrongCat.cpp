#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat Default constructor called." << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat Constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj)
{
	this->type = obj.type;
	std::cout << "WrongCat Copy constructor called." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& obj)
{
	if (this != &obj)
		this->type = obj.type;
	std::cout << "WrongCat Copy assignment operator called." << std::endl;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat make sound" << std::endl;
}
