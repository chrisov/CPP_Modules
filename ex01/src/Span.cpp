#include "../inc/Span.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Span::Span() : _N(1) {
	_cont.reserve(1);
	std::cout << "Default span constructor called!" << std::endl;
}

Span::Span(unsigned int num) : _N(num) {
	_cont.reserve(_N);
	std::cout << "Parameterized span constructor called!" << std::endl;
}

Span::Span(const Span& other) : _N(other._N), _cont(other._cont) {
	std::cout << "Copy span constructor called!" << std::endl; 
}

Span::~Span(){
	std::cout << "Default destructor called!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

Span&	Span::operator=(const Span& other) {
	if (this != &other) {
		_N = other._N;
		_cont = other._cont;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Span& obj) {
	int	count = 0;
	for (auto i : obj.getCont()) {
		out << std::setw(10) << std::left << i;
		++count;
		if (count % 8 == 0)
			out << '\n';
		else
			std::cout << '\t'; 
	}
	return (out);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

void	Span::addNumber(int num) {
	if (_cont.size() == _cont.capacity())
		throw ContainerAlreadyFullException();
	_cont.push_back(num);
}

unsigned int	Span::getN(void) const {
	return (_N);
}

std::vector<int>&	Span::getCont(void) {
	return (_cont);
}

const std::vector<int>&	Span::getCont(void) const {
	return (_cont);
}

int	Span::shortestSpan(void) const {
	if (_cont.size() < 2)
		throw InvalidContainerSpanException();
	int	res = INT_MAX;
	std::vector<int> temp = _cont;
	std::sort(temp.begin(), temp.end());
	auto it = temp.begin();
	auto next = std::next(it);
	while (next != temp.end()) {
		if (*next - *it < res)
			res = *next - *it;
		it++;
		next++;
	}
	return (res);
}

int	Span::longestSpan(void) const {
	if (_cont.size() < 2)
		throw InvalidContainerSpanException();
	std::vector<int> temp = _cont;
	std::sort(temp.begin(), temp.end());
	return (*temp.rbegin() - *temp.begin());
}

void	Span::randomFill(void) {
	std::srand(std::time(nullptr));

	for (size_t i = 0; i < _cont.capacity(); i++)
		_cont.push_back(std::rand() % (int)10e+6 + 1);
}

/****************************************************
*					EXCEPTIONS						*
****************************************************/

const char*	Span::ContainerAlreadyFullException::what(void) const noexcept {
	return ("Container is already full!");
}

const char*	Span::InvalidContainerSpanException::what(void) const noexcept {
	return ("Invalid container for span!");
}