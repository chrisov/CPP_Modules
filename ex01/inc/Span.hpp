#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <unordered_set>
#include <random>
#include <iomanip>
#include <algorithm>
#include <climits>
#include "Colors.hpp"

class Span {
	
	private:
		std::vector<int>	_cont;
		std::pair<int, int>	_shortest;
		std::pair<int, int>	_longest;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		~Span();

		Span&	operator=(const Span& other);

		const std::vector<int>&		getCont(void) const;
		const std::pair<int, int>	getShortest(void) const;
		const std::pair<int, int>	getLongest(void) const;
		void						addNumber(int num);
		int							shortestSpan(void);
		int							longestSpan(void);
		void						randomFill(void);

		class ContainerAlreadyFullException : public std::exception {
			public:
				const char*	what(void) const noexcept override;
		};

		class InvalidContainerSpanException : public std::exception {
			public:
				const char*	what(void) const noexcept override;
		};

};

std::ostream&	operator<<(std::ostream& out, const Span& obj);

#endif