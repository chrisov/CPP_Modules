#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include "Utils.hpp"

#define NOVALUE 100

typedef struct	oper_s {
	union {
		char	oprtr;
		int		oprnd;
	};
}	oper_t;

class RPN {
	private:
		std::stack<oper_t>	_oper;

	public:
		RPN();
		RPN(const RPN& other);
		~RPN();

		RPN& operator=(const RPN& other);

		std::stack<oper_t>	getOper(void) const;
		void				parseParam(std::string str);
};

std::ostream&	operator<<(std::ostream& out, const RPN& obj);

#endif