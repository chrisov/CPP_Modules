#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>

#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>

class ElementNotFound : std::exception {
	public:
		const char*	what(void) const noexcept override;	
};

template <typename T>
void	easyfind(T& cont, int val);

#include "../src/easyfind.tpp"

#endif