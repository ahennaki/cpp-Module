#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = 0;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack(void)
{
	if (this->weapon)
	{
		std::cout << this->name << " attacks using their ";
		std::cout << weapon->getType();
		std::cout << std::endl;
	}
	else
		std::cout << "attack feiled!!" << std::endl;
}

HumanB::~HumanB(){}
