#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include "Utils.hpp"

class RPN {
	private:
		std::stack<int>	_oper;

	public:
		RPN();
		RPN(const RPN& other);
		~RPN();

		RPN& operator=(const RPN& other);

		std::stack<int>	getOper(void) const;
		void			parseNExecute(std::string str);
		void			emptyStack(void);
};

std::ostream&	operator<<(std::ostream& out, const RPN& obj);

#endif