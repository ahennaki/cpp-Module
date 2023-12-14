#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& obj);
		virtual ~Animal();
		Animal &operator=(const Animal& obj);
		
		virtual void makeSound() const = 0;
		
		void setType(const std::string& type);
		const std::string& getType() const;
};

#endif
