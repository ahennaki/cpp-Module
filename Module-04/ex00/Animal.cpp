#include "Animal.hpp"

Animal::Animal()
{
	type = "unknown";
	std::cout << "Default constructor called." << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Constructor called." << std::endl;
}

Animal::Animal(const Animal& obj)
{
	this->type = obj.type;
	std::cout << "Copy constructor called." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Default destructor called." << std::endl;
}

Animal &Animal::operator=(const Animal& obj)
{
	if (this != &obj)
		this->type = obj.type;
	std::cout << "Copy assignment operator called." << std::endl;
	return (*this);
}

void Animal::makeSound()
{
	std::cout << "Animal make sound" << std::endl;
}

void Animal::setType(const std::string& type)
{
	this->type = type;
}

const 
