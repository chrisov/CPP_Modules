#include "../inc/Bitcoin.hpp"

std::map<Date, float> Bitcoin::_db;

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Bitcoin::Bitcoin() : _date(), _value(0) {
	std::cout << "Default " << color("Bitcoin", YLW) << color(" constructor", GRN) << " called!" << std::endl;
}

Bitcoin::Bitcoin(Date date, float value) : _date(date), _value(value) {
	std::cout << "Copy " << color("Bitcoin", YLW) << color(" constructor", GRN) << " called!" << std::endl;
}

Bitcoin::Bitcoin(const Bitcoin& other) : _date(other._date), _value(other._value) {}

Bitcoin::~Bitcoin() {
		std::cout << color("Bitcoin", YLW) << color(" destructor", RED) << " called!" << std::endl;
}

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
	std::ifstream	db(DB_FILENAME);
	std::string		line;
	char**			matrix;
	Date			date;

	if (db.is_open()) {	
		getline(db, line);
		while (getline(db, line)) {
			matrix = Parse::split(line, ',');
			if (!matrix)
				return (false);
			date.setDate(matrix[0]);
			_db.emplace(date, std::strtof(matrix[1], nullptr));
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
		if (line.empty())
			continue;
		matrix = Parse::split(line, '|');
		if (std::string(matrix[0]).find('-') == std::string::npos) {
			std::cerr << color("Error", RED) << ": Incorrect Date format!" << std::endl;
			Parse::freeCharArray(matrix);
			continue;
		}
		try {
			infile_date.setDate(matrix[0]);
		}
		catch (const DateException& e) {
			std::cerr << color("Error", RED) << ": " << e.what() << " => " << infile_date << std::endl;
			Parse::freeCharArray(matrix);
			continue ;
		}
		btc.setDate(infile_date);
		try {
			infile_value = std::strtof(matrix[1], nullptr);
			if (infile_value < 0)
				throw NegativeValueException();
			if (infile_value > 1000)
				throw ExtremelyLargeValueException();
		}
		catch (const BTCException& e) {
			std::cerr << color("Error", RED) << ": " << e.what() << " => " << std::strtol(matrix[1], nullptr, 10) << std::endl;
			Parse::freeCharArray(matrix);
			continue ;
		}
		btc.setValue(infile_value);
		btc.searchDb();
		Parse::freeCharArray(matrix);
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
		std::cerr << color("Error", RED) << ": Too early infile date! => " << _date << std::endl; 
}

std::map<Date, float>&	Bitcoin::getDb(void) {
	return (_db);
}

Date	Bitcoin::getDate(void) const {
	return (_date);
}

float	Bitcoin::getValue(void) const {
	return (_value);
}

void	Bitcoin::setDate(Date date) {
	_date = date;
}

void	Bitcoin::setValue(float val) {
	_value = val;
}
