#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// void f(){system("leaks Animal");}

int main()
{
	// atexit(f);
	const Animal* meta = new Animal();
	const Animal* j = new Dog("dog");
	const Animal* i = new Cat("cat");

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	std::cout << "----------wrongAnimal---------" << std::endl;
	WrongAnimal *wrongAnimal = new WrongAnimal();
	WrongAnimal *wrongCat = new WrongCat();

	wrongAnimal->makeSound();
	wrongCat->makeSound();

	delete wrongAnimal;
	delete wrongCat;

	return 0;
}