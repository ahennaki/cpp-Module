#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "unknown";
	std::cout << "WrongAnimal Default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "WrongAnimal Constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	this->type = obj.type;
	std::cout << "WrongAnimal Copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& obj)
{
	if (this != &obj)
		this->type = obj.type;
	std::cout << "WrongAnimal Copy assignment operator called." << std::endl;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal make sound" << std::endl;
}

void WrongAnimal::setType(const std::string& type)
{
	this->type = type;
}

const std::string& WrongAnimal::getType() const
{
	return (this->type);
}
