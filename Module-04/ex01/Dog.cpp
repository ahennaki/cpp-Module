#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	brain = new Brain();
	std::cout << "Dog Default constructor called." << std::endl;
}

Dog::Dog(const Dog& obj)
{
	this->type = obj.type;
	this->brain = new Brain(*(obj.brain));
	std::cout << "Dog Copy constructor called." << std::endl;
}

Dog &Dog::operator=(const Dog& obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
		this->brain = new Brain(*(obj.brain));
	}
	std::cout << "Dog Copy assignment operator called." << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog make sound" << std::endl;
}
