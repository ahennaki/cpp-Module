#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat")
{
	brain = new Brain();
	std::cout << "Cat Default constructor called." << std::endl;
}

Cat::Cat(const Cat& obj)
{
	this->type = obj.type;
	this->brain = new Brain(*(obj.brain));
	std::cout << "Cat Copy constructor called." << std::endl;
}

Cat &Cat::operator=(const Cat& obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
		this->brain = new Brain(*(obj.brain));
	}
	std::cout << "Cat Copy assignment operator called." << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat make sound" << std::endl;
}
