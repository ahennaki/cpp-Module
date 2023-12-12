#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Default constructor called." << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Constructor called." << std::endl;
}

Dog::Dog(const Dog& obj)
{
	this->type = obj.type;
	std::cout << "Copy constructor called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Default destructor called." << std::endl;
}

Dog &Dog::operator=(const Dog& obj)
{
	if (this != &obj)
		this->type = obj.type;
	std::cout << "Copy assignment operator called." << std::endl;
	return (*this);
}

void Dog::makeSound()
{
	std::cout << "Dog make sound" << std::endl;
}
