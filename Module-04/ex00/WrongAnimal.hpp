#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& obj);
		~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal& obj);
		
		void makeSound() const;
		
		void setType(const std::string& type);
		const std::string& getType() const;
};

#endif
