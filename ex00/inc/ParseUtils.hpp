#ifndef PARSEUTILS_HPP
#define PARSEUTILS_HPP

#include <iostream>
#include <fstream>
#include <vector>

class Parse {
	
	private:
		Parse() = delete;
		Parse(const Parse& other) = delete;
		~Parse() = delete;

		Parse&	operator=(const Parse& other) = delete;

	public:
		static char**	split(const std::string& str, char delim);
		static void		freeCharArray(char **arr);
		static void		parseInfile(std::ifstream& f);

};

#endif