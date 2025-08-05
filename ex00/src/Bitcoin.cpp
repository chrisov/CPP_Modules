#include "../inc/Bitcoin.hpp"

std::map<Date, double> Bitcoin::_db;

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Bitcoin::Bitcoin() : _date(), _value(0) {}

Bitcoin::Bitcoin(Date date, double value) : _date(date), _value(value) {}

Bitcoin::Bitcoin(const Bitcoin& other) : _date(other._date), _value(other._value) {}

Bitcoin::~Bitcoin() {}

/****************************************************
*					OPERATORS						*
****************************************************/

Bitcoin&	Bitcoin::operator=(const Bitcoin& other) {
	if (this != &other) {
		_date = other._date;
		_value = other._value;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const std::map<Date, double>& obj) {
	unsigned int	count = 0;
	out << '{';
	for (auto const& [key, value] : obj) {
		out << '{' << key << ", " << value << '}';
		count++;
		if (count % 3 == 0 && count < obj.size())
			out << '\n';
		else if (count < obj.size())
			out << ",\t";
	}
	return (out);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

bool	Bitcoin::initDb(void) {
	std::ifstream	db("data.csv");
	std::string		line;
	char**			matrix;
	Date			date;

	if (db.is_open()) {	
		getline(db, line);
		while (getline(db, line)) {
			matrix = Parse::split(line, ',');
			date.setDate(matrix[0]);
			_db[date] = std::strtod(matrix[1], nullptr);
			Parse::freeCharArray(matrix);
		}
		db.close();
		return (true);
	}
	return (false);
}

void	Bitcoin::searchDb(void) const {
	auto it = _db.upper_bound(_date);

	if (it != _db.begin()) {
		--it;
		std::cout << (*it).first.getYear() << '-';
		if ((*it).first.getMonth() < 10)
			std::cout << '0';
		std::cout << (*it).first.getMonth() << '-';
		if ((*it).first.getDay() < 10)
			std::cout << '0';
		std::cout << (*it).first.getDay() << " => ";
		std::cout << _value << " = " << (*it).second * _value << std::endl;
	}
	else
		std::cerr << color("Error", RED) << ": Too early infile date!" << std::endl; 
}

std::map<Date, double>&	Bitcoin::getDb(void) {
	return (_db);
}

Date	Bitcoin::getDate(void) const {
	return (_date);
}

double	Bitcoin::getValue(void) const {
	return (_value);
}

void	Bitcoin::setDate(Date date) {
	_date = date;
}

void	Bitcoin::setValue(double val) {
	_value = val;
}

/****************************************************
*					EXCEPTIONS						*
****************************************************/

const char*	Bitcoin::NegativeValueException::what(void) const noexcept {
	return ("Not a positive value!");
}

const char*	Bitcoin::ExtremelyLargeValueException::what(void) const noexcept {
	return ("Too large number!");
}
