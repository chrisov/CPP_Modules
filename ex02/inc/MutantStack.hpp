#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

	using iterator = typename std::deque<T>::iterator;

	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		~MutantStack();

		MutantStack&	operator=(const MutantStack& other);

		// iterator		begin();
		// iterator		end();
		// const_iterator	begin() const;
		// const_iterator	end() const;
		
		void			push(T elem);
		void			top(void);
		void			size(void);
		void			pop(void);
};

template <typename T>
std::ostream&	operator<<(std::ostream& out, const MutantStack<T>& obj);

#include "../src/MutantStack.tpp"

#endif