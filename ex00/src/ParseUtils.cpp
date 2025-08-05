#include "../inc/ParseUtils.hpp"
#include "../inc/Bitcoin.hpp"

char** Parse::split(const std::string& str, char delim) {
	std::vector<char*> tokens;
	size_t start = 0;
	size_t end;

	while ((end = str.find(delim, start)) != std::string::npos) {
		std::string token = str.substr(start, end - start);
		char* cstr = new char[token.length() + 1];
		std::strcpy(cstr, token.c_str());
		tokens.push_back(cstr);
		start = end + 1;
	}
	std::string token = str.substr(start);
	char* cstr = new char[token.length() + 1];
	std::strcpy(cstr, token.c_str());
	tokens.push_back(cstr);
	char** result = new char*[tokens.size() + 1];
	for (size_t i = 0; i < tokens.size(); ++i) {
		result[i] = tokens[i];
	}
	result[tokens.size()] = nullptr;
	return (result);
}

void	Parse::freeCharArray(char** arr) {
	size_t	size = 0;

	if (!arr)
		return ;
	while (arr[size])
		size++;
	for (size_t i = 0; i < size; i++)
		delete[] arr[i];
	delete[] arr;
}

void	Parse::parseInfile(std::ifstream& f) {
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
