#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>

#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>

class ElementNotFoundException : std::exception {
	public:
		ElementNotFoundException();
		ElementNotFoundException(const ElementNotFoundException& other) = delete;
		~ElementNotFoundException();

		ElementNotFoundException&	operator=(const ElementNotFoundException& other) = delete;

		const char*	what(void) const noexcept override;	
};

template <typename T>
void	easyFind(T& cont, int val);

template <typename T>
void	printArray(T arr);

#include "../src/EasyFind.tpp"

#endif