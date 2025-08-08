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
	std::stack<int> temp = obj.getOper();
	std::stack<int> pmet;

	while (!temp.empty()) {
		pmet.push(temp.top());
		temp.pop();
	}
	while (!pmet.empty()) {
			out << pmet.top();
		out << " ";
		pmet.pop();
	}
	return (out);
}
/****************************************************
*					FUNCTIONS						*
****************************************************/

std::stack<int>	RPN::getOper(void) const {
	return (_oper);
}

static void	executeOperator(std::stack<int>& s, char op) {
	int num1;
	int num2;

	num1 = s.top();
	s.pop();
	num2 = s.top();
	s.pop();
	switch (op) {
		case '+':
			s.push(num1 + num2);
			break ;
		case '-':
			s.push(num2 - num1);
			break ;
		case '*':
			s.push(num1 * num2);
			break ;
		case '/':
			s.push(num2 / num1);
			break ;
		default:
			std::cerr << "Operator not found!" << std::endl;
	}
}

void	RPN::parseNExecute(std::string str) {
	char**	matrix = Utils::split(str, ' ');
	int		val;
	
	int		i = -1;
	while (matrix[++i]) {
		try {
			val = std::stoi(matrix[i]);
			_oper.push(val);
		}
		catch (const std::invalid_argument& e) {
			if (i == 0 || i == 1) {
				std::cerr << "Error!" << std::endl;
				break ;
			}
			executeOperator(_oper, *matrix[i]);
		}
	}
	Utils::freeCharArray(matrix);
}
