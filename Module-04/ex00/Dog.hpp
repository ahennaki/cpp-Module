#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
	protected:
		std::string type;
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog& obj);
		~Dog();
		Dog &operator=(const Dog& obj);
		void makeSound();
};

#endif
