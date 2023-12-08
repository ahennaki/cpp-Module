#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	name = "unknown";
	hitPoint = 10;
	enrgPoint = 10;
	atkDamage = 10;
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	hitPoint = 10;
	enrgPoint = 10;
	atkDamage = 10;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	this->name = obj.name;
	this->hitPoint = obj.hitPoint;
	this->enrgPoint = obj.enrgPoint;
	this->atkDamage = obj.atkDamage;
	std::cout << "Copy constructor called." << std::endl;
}

ClapTrap::~ClapTrap(){}

ClapTrap &ClapTrap::operator=(const ClapTrap& obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
		this->hitPoint = obj.hitPoint;
		this->enrgPoint = obj.enrgPoint;
		this->atkDamage = obj.atkDamage;
	}
	std::cout << "Copy assignment operator called." << std::endl;
	return (*this);
}

void    ClapTrap::attack(std::string const& target)
{
    if (enrgPoint <= 0)
    {
        std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << atkDamage << " points of damage!" << std::endl;
    enrgPoint--;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoint <= amount)
    {
        std::cout << "ClapTrap " << name << " can't take damage!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " takes " << amount << " damage!" << std::endl;
    hitPoint -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (enrgPoint <= amount)
    {
        std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points!" << std::endl;
    enrgPoint--;
    hitPoint += amount;
}
