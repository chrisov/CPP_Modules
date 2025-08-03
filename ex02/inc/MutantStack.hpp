#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

	public:
	
		// using iterator = typename std::deque<T>::iterator;

		MutantStack();
		MutantStack(const MutantStack& other);
		~MutantStack();

		MutantStack&	operator=(const MutantStack& other);

		std::deque<T>	getC(void) const;
		typename std::deque<T>::iterator		begin();
		// iterator		end();
		// const_iterator	begin() const;
		// const_iterator	end() const;
};

template <typename T>
std::ostream&	operator<<(std::ostream& out, const MutantStack<T>& obj);

#include "../src/MutantStack.tpp"

#endif