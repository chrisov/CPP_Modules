#include "../inc/Span.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Span::Span() : _shortest(0, 0), _longest(0, 0) {
	_cont.reserve(1);
	std::cout << "Default " << color("span", YLW) << color(" constructor", GRN) << " called!" << std::endl;
}

Span::Span(unsigned int num) : _shortest(0, 0), _longest(0, 0) {
	_cont.reserve(num);
	std::cout << "Parameterized " << color("span", YLW) << color(" constructor", GRN) << " called!" << std::endl;
}

Span::Span(const Span& other) : _cont(other._cont), _shortest(0, 0), _longest(INT_MAX, INT_MAX) {
	std::cout << "Copy " << color("span", YLW) << color(" constructor", GRN) << " called!" << std::endl;
}

Span::~Span(){
	std::cout << color("Span", YLW) << color(" destructor", RED) << " called!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

Span&	Span::operator=(const Span& other) {
	if (this != &other) {
		_cont = other._cont;
		_shortest = other._shortest;
		_longest = other._longest;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Span& obj) {
	unsigned int	count = 0;
	for (auto i : obj.getCont()) {
		if (i == obj.getShortest().first || i == obj.getShortest().second)
			out << std::setw(8) << std::left << color(std::to_string(i), MGD);
		else if (i == obj.getLongest().first || i == obj.getLongest().second)
			out << std::setw(8) << std::left << color(std::to_string(i), CYA);
		else
			out << std::setw(7) << std::left << i;
		++count;
		if (count % 5 == 0)
			out << '\n';
		else
			std::cout << "\t\t"; 
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

std::vector<int>&	Span::getCont(void) {
	return (_cont);
}

const std::vector<int>&	Span::getCont(void) const {
	return (_cont);
}

const std::pair<int, int>	Span::getShortest(void) const{
	return (_shortest);
}

const std::pair<int, int>	Span::getLongest(void) const {
	return (_longest);
}

int	Span::shortestSpan(void) {
	if (_cont.size() < 2)
		throw InvalidContainerSpanException();
	int	res = INT_MAX;
	std::vector<int> temp = _cont;
	std::sort(temp.begin(), temp.end());
	auto it = temp.begin();
	auto next = std::next(it);
	while (next != temp.end()) {
		if (*next - *it < res) {
			res = *next - *it;
			_shortest = std::make_pair(*it, *next);
		}
		it++;
		next++;
	}
	return (res);
}

int	Span::longestSpan(void) {
	if (_cont.size() < 2)
		throw InvalidContainerSpanException();
	std::vector<int> temp = _cont;
	std::sort(temp.begin(), temp.end());
	_longest = std::make_pair(*temp.begin(), *temp.rbegin());
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
	return ("Container is already \033[31mfull\033[0m!");
}

const char*	Span::InvalidContainerSpanException::what(void) const noexcept {
	return ("\033[31mIvalid\033[0m container for span measurement!");
}