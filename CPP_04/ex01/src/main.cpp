#include <iostream>

#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

int main()
{
	std::cout << "\nv------------------------------------------v\n";
	std::cout << "                   TEST 1";
	std::cout << "\n^------------------------------------------^\n" << std::endl;
	{
		Animal* animals[10];
	
		for (int i = 0; i < 5 ; i++) {
			animals[i] = new Dog("Good boi");
		}
		for (int i = 5; i < 10;i++) {
			animals[i] = new Cat("World domination");
		}
	
		std::cout << std::endl;
		for (int i = 0; i < 10; i++) {
			animals[i]->makeSound();
			std::cout << YLW << animals[i]->getType() << RST << ": ";
			animals[i]->getBrain()->speakUp();
		}
	
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			delete animals[i];
	}
	std::cout << "\nv------------------------------------------v\n";
	std::cout << "                   TEST 2";
	std::cout << "\n^------------------------------------------^\n" << std::endl;
	{
		Dog		dog1("I am the best!");
		Dog		dog2;

		std::cout << "\nDog1: '" << dog1.getType() << "'" << std::endl;
		dog1.getBrain()->speakUp();
		dog1.makeSound();
	
		std::cout << "\nDog2: '" << dog2.getType() << "'" << std::endl;
		dog2.getBrain()->speakUp();
		dog2.getBrain()->changedMyMind("I am the second best?");
		dog2.getBrain()->speakUp();
		dog2.makeSound();
		std::cout << std::endl;
	}

	return 0;
}