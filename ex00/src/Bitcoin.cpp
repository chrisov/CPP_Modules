#include "../inc/Bitcoin.hpp"

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
	unsigned int	count = 1;
	out << '{';
	for (auto it = obj.begin(); it != obj.end(); ++it) {
		out << '{' << it->first << ", " << it->second << '}';
		if ((count + 1) % 5 == 0)
			out << '\n';
		else if (std::next(it) != obj.end())
			out << ", ";
	}
	return (out);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

bool	Bitcoin::initDb(void) {
	std::ifstream db("data.csv");
	if (db.is_open()) {
		Bitcoin::parseDb(db);
		db.close();
		return (true);
	}
	return (false);
}

void	Bitcoin::parseDb(std::ifstream& f) {
	std::string	line;
	char**		matrix;
	Date		date;
	double		value;

	while (getline(f, line)) {
		matrix = Parse::split(line, ',');
		try {
			date.setDate(matrix[0]);
		}
		catch (const std::exception& e) {
			std::cerr << "Parsing Failed: " << e.what() << std::endl;
			continue ;
		}
		value = std::strtod(matrix[1], nullptr);
		try {
			if (value < 0 || value > 1000)
				throw ValueOutOfRange();
		}
		catch (const std::exception& e) {
			std::cerr << "Parsing Failed: " << e.what() << std::endl;
			continue ;
		}
		_db[date] = atoi(matrix[1]);
		delete matrix;
	}
}

/****************************************************
*					EXCEPTIONS						*
****************************************************/

const char*	Bitcoin::ValueOutOfRange::what(void) const noexcept {
	return ("Value out of range!");
}