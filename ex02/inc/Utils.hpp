#ifndef UTILS_HPP
#define UTILS_HPP

#define RST "\033[0m"
#define RED "\033[31m"
#define GRN "\033[32m"
#define YLW "\033[33m"

#include <iostream>
#include <iomanip>
#include <cstring>
	
namespace utils {
	const std::string	color(const std::string& text, const std::string& col);
	char**				split(const std::string& str, char delim);
    void				freeCharArray(char **arr);
	int					arraySize(char **arr);

	template <typename cont>
	void	printCont(cont con) {
		int	count = 0;

		if (con.begin() == con.end())
			std::cout << "'null'";
		else {
			for (auto it = con.begin(); it != con.end(); ++it) {
				std::cout << *it;
				count++;
				if (count % 10 == 0)
					std::cout << "\n\t";
				else if (std::next(it) != con.end())
					std::cout << std::setw(7);
			}
		}
	}

	template <typename cont>
	void	freeArrayCont(cont**& con) {
		if (con) {
			for (size_t i = 0; con[i] != nullptr; ++i)
				delete con[i];
			delete[] con;
			con = nullptr;
		}
	}
}

#endif
