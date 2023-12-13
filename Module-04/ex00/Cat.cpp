#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat Default constructor called." << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat Constructor called." << std::endl;
}

Cat::Cat(const Cat& obj)
{
	this->type = obj.type;
	std::cout << "Cat Copy constructor called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}

Cat &Cat::operator=(const Cat& obj)
{
	if (this != &obj)
		this->type = obj.type;
	std::cout << "Cat Copy assignment operator called." << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat make sound" << std::endl;
}
