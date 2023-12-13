#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	protected:
		std::string type;
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat& obj);
		~Cat();
		Cat &operator=(const Cat& obj);
		
		void makeSound() const;
};

#endif
