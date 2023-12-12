#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	hitPoint = 100;
	enrgPoint = 100;
	atkDamage = 30;
	std::cout << "Default constructor FragTrap called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoint = 100;
	enrgPoint = 100;
	atkDamage = 30;
	std::cout << "Constructor FragTrap called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
		this->hitPoint = obj.hitPoint;
		this->enrgPoint = obj.enrgPoint;
		this->atkDamage = obj.atkDamage;
	}
	std::cout << "Copy constructor FragTrap called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
		this->hitPoint = obj.hitPoint;
		this->enrgPoint = obj.enrgPoint;
		this->atkDamage = obj.atkDamage;
	}
	std::cout << "Copy assignment operator FragTrap called." << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor FragTrap called." << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " requests a high five from the guys! Anyone up for it?" << std::endl;
}
