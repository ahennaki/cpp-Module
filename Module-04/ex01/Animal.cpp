#include "Animal.hpp"

Animal::Animal()
{
	type = "unknown";
	std::cout << "Animal Default constructor called." << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal Constructor called." << std::endl;
}

Animal::Animal(const Animal& obj)
{
	this->type = obj.type;
	std::cout << "Animal Copy constructor called." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}

Animal &Animal::operator=(const Animal& obj)
{
	if (this != &obj)
		this->type = obj.type;
	std::cout << "Animal Copy assignment operator called." << std::endl;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Animal make sound" << std::endl;
}

void Animal::setType(const std::string& type)
{
	this->type = type;
}

const std::string& Animal::getType() const
{
	return (this->type);
}
