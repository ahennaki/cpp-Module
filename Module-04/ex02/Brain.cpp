#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called." << std::endl;
}

Brain::Brain(const Brain& obj)
{
	*this = obj;
	std::cout << "Brain copy constructoor called." << std::endl;
}

Brain &Brain::operator=(const Brain& obj)
{
	if (this != &obj)
		for (size_t i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}
