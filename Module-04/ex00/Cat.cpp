#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Default constructor called." << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat& obj)
{
	*this = obj;
	std::cout << "Cat Copy constructor called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}

Cat &Cat::operator=(const Cat& obj)
{
	if (this != &obj)
		*this = obj;
	std::cout << "Cat Copy assignment operator called." << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat make sound" << std::endl;
}
