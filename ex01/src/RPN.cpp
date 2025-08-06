#include "../inc/RPN.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

RPN::RPN() {
	std::cout << "Default " << Utils::color("RPN", YLW) << Utils::color(" constructor", GRN) << " called!" << std::endl;
}

RPN::RPN(const RPN& other) : _oper(other._oper) {
	std::cout << "Copy " << Utils::color("RPN", YLW) << Utils::color(" constructor", GRN) << " called!" << std::endl;
}

RPN::~RPN() {
	std::cout << Utils::color("RPN", YLW) << Utils::color(" destructor", RED) << " called!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

RPN&	RPN::operator=(const RPN& other) {
	if (this != &other) {
		_oper = other._oper;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const RPN& obj) {
	std::stack<oper_t> temp = obj.getOper();

	while (!temp.empty()) {
		// out << (temp.top().oprtr == '\0' ? temp.top().oprnd : temp.top().oprtr) << '\n';
		if (temp.top().oprtr != '\0')
			out << temp.top().oprtr;
		else
			out << temp.top().oprnd;
		out << " ";
		temp.pop();
	}
	return (out);
}
/****************************************************
*					FUNCTIONS						*
****************************************************/

std::stack<oper_t>	RPN::getOper(void) const {
	return (_oper);
}

void	RPN::parseParam(std::string str) {
	char**	matrix = Utils::split(str, ' ');
	oper_t	oper;
	
	int		i = -1;
	while (matrix[++i]) {
		try {
			oper.oprnd = std::stoi(matrix[i]);
			// oper.oprtr = '\0';
		}
		catch (const std::invalid_argument& e) {
			// oper.oprnd = NOVALUE;
			oper.oprtr = *matrix[i];
		}
		_oper.push(oper);
		// std::cout << "oper: " << oper.oprtr << ", val: " << oper.oprnd << std::endl;
	}
	Utils::freeCharArray(matrix);
}