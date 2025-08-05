#include "../inc/Date.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Date::Date() : _year(0), _month(0), _day(0) {
	// std::cout << "Default " << color("Date", YLW) << color(" constructor", GRN) << " called!" << std::endl;
}

Date::Date(const Date& other) : _year(other._year), _month(other._month), _day(other._day) {
	// std::cout << "Copy " << color("Date", YLW) << color(" constructor", GRN) << " called!" << std::endl;
}

Date::Date(int year, int month, int day) : _year(year), _month(month), _day(day) {
	std::cout << "Parameterized " << color("Date", YLW) << color(" constructor", GRN) << " called!" << std::endl;
}

Date::~Date() {
	// std::cout << color("Date", YLW) << color(" destructor", RED) << " called!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

Date&	Date::operator=(const Date& other) {
	if (this != &other) {
		_year = other._year;
		_month = other._month;
		_day = other._day;
	}
	return (*this);
}

bool	Date::operator<(const Date& other) const {
	if (_year < other._year)
		return (true);
	if (_year > other._year)
		return (false);
	if (_month < other._month)
		return (true);
	if (_month > other._month)
		return (false);
	return (_day < other._day);
}

bool	Date::operator>(const Date& other) const {
	if (_year > other._year)
		return (true);
	if (_year < other._year)
		return (false);
	if (_month > other._month)
		return (true);
	if (_month < other._month)
		return (false);
	return (_day > other._day);
}

std::ostream&	operator<<(std::ostream& out, const Date& obj) {
	out << obj.getYear() << '-' << obj.getMonth() << '-' << obj.getDay();
	return (out);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

void Date::setDate(char *date) {
	char **matrix = Parse::split(date, '-');

	_year = atoi(matrix[0]);
	_month = atoi(matrix[1]);
	if (_month < 1 || _month > 12)
		throw MonthOutOfRangeException();
	_day = atoi(matrix[2]);
	if (_month == 2 && (_day < 1 || _day > 29))
		throw DayOutOfRangeException();
	if (_day < 1 || _day > 31)
		throw DayOutOfRangeException();
	Parse::freeCharArray(matrix);
}

int	Date::getYear(void) const {
	return (_year);
}

int	Date::getMonth(void) const {
	return (_month);
}

int	Date::getDay(void) const {
	return (_day);
}

/****************************************************
*					EXCEPTIONS						*
****************************************************/

const char*	Date::DayOutOfRangeException::what(void) const noexcept {
	return ("Day out of range!");
}

const char*	Date::MonthOutOfRangeException::what(void) const noexcept {
	return ("Month out of range!");
}
