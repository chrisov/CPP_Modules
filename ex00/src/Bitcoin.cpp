#include "../inc/Bitcoin.hpp"

std::map<Date, double> Bitcoin::_db;

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Bitcoin::Bitcoin(Date date, int value) : _date(date), _value(value) {
	std::cout << "Parameterized " << color("bitcoin ", YLW) << color("constructor", GRN) << " called!" << std::endl;
}

Bitcoin::Bitcoin(const Bitcoin& other) : _date(other._date), _value(other._value) {
	std::cout << "Copy " << color("bitcoin ", YLW) << color("constructor", GRN) << " called!" << std::endl;
}

Bitcoin::~Bitcoin() {
	std::cout << color("Bitcoin", YLW) << color(" destructor", GRN) << " called!" << std::endl;
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
	std::ifstream db("data.csv");
	std::string	line;
	char**		matrix;
	Date		date;

	if (db.is_open()) {	
		getline(db, line);
		while (getline(db, line)) {
			matrix = Parse::split(line, ',');
			try {
				date.setDate(matrix[0]);
			}
			catch (const std::exception& e) {
				std::cerr << "Parsing Failed: " << e.what() << std::endl;
				return (delete matrix, false);
			}
			_db[date] = std::strtod(matrix[1], nullptr);
			Parse::freeCharArray(matrix);
		}
		db.close();
		return (true);
	}
	return (false);
}

std::map<Date, double>&	Bitcoin::getDb(void) {
	return (_db);
}
/****************************************************
*					EXCEPTIONS						*
****************************************************/

const char*	Bitcoin::ValueOutOfRange::what(void) const noexcept {
	return ("Value out of range!");
}