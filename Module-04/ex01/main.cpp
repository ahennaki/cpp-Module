#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// void f(){system("leaks Animal");}

int main()
{
	// atexit(f);
	Animal* a = new Dog();
	Animal* b = new Cat();
	
	delete a;//should not create a leak
	delete b;

	std::cout << std::endl;

	Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };

	for (size_t i = 0; i < 4; i++)
		delete animals[i];

	return 0;
}