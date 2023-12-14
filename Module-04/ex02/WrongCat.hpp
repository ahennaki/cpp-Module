#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat& obj);
		~WrongCat();
		WrongCat &operator=(const WrongCat& obj);
		
		void makeSound() const;
};

#endif
