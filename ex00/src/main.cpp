#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();
	const WrongAnimal* wrongcat = new WrongCat();

	std::cout << "\ntype: " << animal->getType() << std::endl;
	animal->makeSound();

	std::cout << "\ntype: " << cat->getType() << std::endl;
	cat->makeSound();

	std::cout << "\ntype: " << dog->getType() << std::endl;
	dog->makeSound();

	std::cout << "\ntype: " << wrongcat->getType() << std::endl;
	wrongcat->makeSound();

	std::cout << std::endl;
	delete animal;
	delete cat;
	delete dog;
	delete wrongcat;
	return 0;
}