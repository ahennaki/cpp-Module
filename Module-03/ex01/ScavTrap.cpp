#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	hitPoint = 100;
	enrgPoint = 50;
	atkDamage = 20;
	std::cout << "Default constructor ScavTrap called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoint = 100;
	enrgPoint = 50;
	atkDamage = 20;
	std::cout << "Constructor ScavTrap called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
		this->hitPoint = obj.hitPoint;
		this->enrgPoint = obj.enrgPoint;
		this->atkDamage = obj.atkDamage;
	}
	std::cout << "Copy constructor ScavTrap called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
		this->hitPoint = obj.hitPoint;
		this->enrgPoint = obj.enrgPoint;
		this->atkDamage = obj.atkDamage;
	}
	std::cout << "Copy assignment operator ScavTrap called." << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap called." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;//to implemente
}
