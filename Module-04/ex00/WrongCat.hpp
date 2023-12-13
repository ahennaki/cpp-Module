#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat& obj);
		~WrongCat();
		WrongCat &operator=(const WrongCat& obj);
		
		void makeSound() const;
};

#endif
