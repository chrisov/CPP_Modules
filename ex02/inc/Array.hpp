#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include "Colors.hpp"

template <typename T>
class Array {
	
	private:
		T*				_data;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int size);
		Array(const Array& other);
		~Array();

		Array&			operator=(const Array& other);
		T&				operator[](unsigned int idx);
		static void*	operator new[](std::size_t size);

		unsigned int	size(void) const; 

		class IndexOutOfBounds : public std::exception {
			public:
				const char*	what(void) const noexcept override;
		};
};

template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& obj);

#include "../src/Array.tpp"

#endif
