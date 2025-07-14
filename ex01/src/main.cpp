#include <iostream>

#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

int main()
{
	Animal* animals[10];

	for (int i = 0; i < 5 ; i++) {
		animals[i] = new Dog("Good boi");
	}
	for (int i = 5; i < 10;i++) {
		animals[i] = new Cat("World domination");
	}
	for (int i = 0; i < 10; i++) {
		animals[i]->makeSound();
		std::cout << YLW << animals[i]->getType() << RST << ": ";
		animals[i]->getBrain()->speakUp();
	}
	for (int i = 0; i < 10; i++)
		delete animals[i];
	return 0;
}