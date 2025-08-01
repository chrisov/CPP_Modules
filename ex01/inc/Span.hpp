#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <random>
#include <iomanip>
#include <algorithm>

class Span {
	
	private:
		unsigned int		_N;
		std::vector<int>	_cont;

	public:
		Span();
		Span(unsigned int num);
		Span(const Span& other);
		~Span();

		Span&	operator=(const Span& other);

		unsigned int			getN(void) const;
		std::vector<int>&		getCont(void);
		const std::vector<int>&	getCont(void) const;
		void					addNumber(int num);
		int						shortestSpan(void) const;
		int						longestSpan(void) const;
		void					randomFill(void);

		class ContainerAlreadyFullException : std::exception {
			public:
				const char*	what(void) const noexcept override;
		};

		class InvalidContainerSpanException : std::exception {
			public:
				const char*	what(void) const noexcept override;
		};

};

std::ostream&	operator<<(std::ostream& out, const Span& obj);

#endif