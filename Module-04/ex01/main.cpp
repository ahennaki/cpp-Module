#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// void f(){system("leaks Animal");}

int main()
{
	// atexit(f);
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << std::endl;
	const Dog *dog = new Dog();
	const Cat *cat = new Cat();

	std::cout << std::endl;
	std::cout << cat->getType() << std::endl; 
	std::cout << dog->getType() << std::endl; 

	std::cout << std::endl;
	delete j;//should not create a leak
	delete i;

	std::cout << std::endl;
	delete dog;
	delete cat;

	return 0;
}