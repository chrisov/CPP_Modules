#include "../inc/FordJohnson.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

FordJohnson::FordJohnson() :
	_main(),
	_pend(),
	_unused() {
	std::cout << "Default " << utils::color("Ford-Johnson ", YLW) << utils::color("constructor ", GRN) << " called!" << std::endl;
}

FordJohnson::FordJohnson(const FordJohnson& other) :
	_main(other._main),
	_pend(other._pend),
	_unused(other._unused) {
	std::cout << "Copy " << utils::color("Ford-Johnson ", YLW) << utils::color("constructor ", GRN) << " called!" << std::endl;
}

FordJohnson::~FordJohnson() {
	std::cout << utils::color("Ford-Johnson", YLW) << utils::color(" destructor", RED) << " called!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

FordJohnson& FordJohnson::operator=(const FordJohnson& other) {
	if (this != &other) {
		_main = other._main;
		_pend = other._pend;
		_unused = other._unused;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const FordJohnson& obj) {
	std::vector<int>	vec[3] = {obj.getMain(), obj.getPend(), obj.getUnused()};
	int					count = 0;

	for (int i = 0; i < 3; i++) {
		for (auto it = vec[i].begin(); it != vec[i].end(); ++it) {
			switch (i) {
				case 0:
					out << utils::color("main", YLW) << ": ";
					break ;
				case 1:
					out << utils::color("pend", YLW) << ": ";
					break ;
				case 2:
					out << utils::color("unused", YLW) << ": ";
					break ;
				default:
					out << "Unknown Ford-Johnson vector!";
			}
			out << std::setw(7) << *it;
			count++;
			if (count % 7 == 0)
				out << "\n\t";
			else if (std::next(it) != vec[i].end())
				out << " ";
		}
	}
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

std::vector<int>&	FordJohnson::getMain(void) {
	return (_main);
}

std::vector<int>	FordJohnson::getMain(void) const {
	return (_main);
}

std::vector<int>&	FordJohnson::getPend(void) {
	return (_pend);
}

std::vector<int>	FordJohnson::getPend(void) const {
	return (_pend);
}

std::vector<int>&	FordJohnson::getUnused(void) {
	return (_unused);
}

std::vector<int>	FordJohnson::getUnused(void) const {
	return (_unused);
}