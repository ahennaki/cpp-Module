#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon(){}

void Weapon::setType(const std::string& type)
{
	std::cout << "am here" << std::endl;
	if (!type.empty())
		this->type = type;
	else
		this->type = "";
}

const std::string& Weapon::getType(void) const
{
	return (this->type);
}
