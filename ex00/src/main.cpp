#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main (void) {
	Animal	a;
	Dog		d;
	Cat		c;

	a.makeSound();
	d.makeSound();
	c.makeSound();
}