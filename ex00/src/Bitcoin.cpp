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

void	Bitcoin::parseInfile(std::ifstream& f) {
	std::string line;
	char**		matrix;
	Bitcoin		btc;
	Date		infile_date;
	double		infile_value;

	getline(f, line);
	while (getline(f, line)) {
		matrix = Parse::split(line, '|');
		try {
			infile_date.setDate(matrix[0]);
		}
		catch (const Date::MonthOutOfRangeException& e) {
			std::cerr << color("Error", RED) << ": " << e.what();
			std::cerr << " => " << infile_date.getYear() << '-';
			std::cerr << color(std::to_string(infile_date.getMonth()), RED) << '-';
			std::cerr << infile_date.getDay() << std::endl; 
			continue ;
		}
		catch (const Date::DayOutOfRangeException& e) {
			std::cerr << color("Error", RED) << ": " << e.what();
			std::cerr << " => " << infile_date.getYear() << '-';
			std::cerr << infile_date.getMonth() << std::endl; 
			std::cerr << color(std::to_string(infile_date.getDay()), RED) << '-';
			continue ;
		}
		btc.setDate(infile_date);
		try {
			infile_value = std::strtod(matrix[1], nullptr);
			if (infile_value < 0)
				throw Bitcoin::NegativeValueException();
			if (infile_value > 1000)
				throw Bitcoin::ExtremelyLargeValueException();
		}
		catch (const Bitcoin::NegativeValueException& e) {
			std::cerr << color("Error", RED) << ": " << e.what() << std::endl;
			continue ;
		}
		catch (const Bitcoin::ExtremelyLargeValueException& e) {
			std::cerr << color("Error", RED) << ": " << e.what() << std::endl;
			continue ;
		}
		btc.setValue(infile_value);
		btc.searchDb();
	}
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
