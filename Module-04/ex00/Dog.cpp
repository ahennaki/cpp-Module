#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Default constructor called." << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog& obj)
{
	*this = obj;
	std::cout << "Dog Copy constructor called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}

Dog &Dog::operator=(const Dog& obj)
{
	if (this != &obj)
		*this = obj;
	std::cout << "Dog Copy assignment operator called." << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Dog make sound" << std::endl;
}
