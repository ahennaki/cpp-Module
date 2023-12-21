#include "Character.hpp"

Character::Character()
{
	name = "";
	for (size_t i = 0; i < 4; i++)
		this->slots[i] = 0;
	// std::cout << "Character default constructor called." << std::endl;
}

Character::Character(std::string name)
{
	this->name = name;
	for (size_t i = 0; i < 4; i++)
		this->slots[i] = 0;
	// std::cout << "Character default constructor called." << std::endl;
}

Character::Character(const Character& obj)
{
	this->name = obj.name;
	for (size_t i = 0; i < 4; i++)
		this->slots[i] = obj.slots[i]->clone();
	// std::cout << "Character Copy constructor called." << std::endl;
}

Character &Character::operator=(const Character& obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
		for (size_t i = 0; i < 4; i++)
		{
			if (this->slots[i])
			{
				delete slots[i];
				slots[i] = 0;
			}
			this->slots[i] = obj.slots[i]->clone();
		}
	}
	// std::cout << "Character Copy assignment operator called." << std::endl;
	return *this;
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
		if (slots[i])
			delete slots[i];
	// std::cout << "Character destructor called." << std::endl;
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	size_t i = 0;

	while (i < 4 && this->slots[i])
		i++;
	if (i != 4)
		this->slots[i] = m;
	// std::cout << "equip() called." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->slots[idx])
		this->slots[idx] = 0;
	// std::cout << "unequip() called." << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->slots[idx])
		slots[idx]->AMateria::use(target);
	else
		std::cout << "AMateria does not exist!" << std::endl;
}
