#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Default constructor called." << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Constructor called." << std::endl;
}

Cat::Cat(const Cat& obj)
{
	this->type = obj.type;
	std::cout << "Copy constructor called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Default destructor called." << std::endl;
}

Cat &Cat::operator=(const Cat& obj)
{
	if (this != &obj)
		this->type = obj.type;
	std::cout << "Copy assignment operator called." << std::endl;
	return (*this);
}

void Cat::makeSound()
{
	std::cout << "Cat make sound" << std::endl;
}
