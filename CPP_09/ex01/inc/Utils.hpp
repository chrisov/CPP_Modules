#ifndef UTILS_HPP
#define UTILS_HPP

#define RST "\033[0m"
#define RED "\033[31m"
#define GRN "\033[32m"
#define YLW "\033[33m"
#define MGD "\033[35m"
#define CYA "\033[36m"

#include <iostream>
#include <cstring>

class Utils {
	
	private:
		Utils() = delete;
		Utils(const Utils& other) = delete;
		~Utils() = delete;

		Utils&	operator=(const Utils& other) = delete;
	
	public:
		static const std::string	color(const std::string& text, const std::string& col);
		static char**				split(const std::string& str, char delim);
		static void					freeCharArray(char **arr);
		static bool					paramCheck(const char *str);
};

#endif