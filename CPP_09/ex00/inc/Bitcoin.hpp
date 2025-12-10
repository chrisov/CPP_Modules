#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#define DB_FILENAME "data.csv"

#include <iostream>
#include <map>
#include <fstream>
#include "Colors.hpp"
#include "Date.hpp"
#include "ParseUtils.hpp"
#include "Exceptions.hpp"

class Bitcoin {

	private:
		Date	_date;
		float	_value;
		
		static std::map<Date, float>	_db;

	public:
		Bitcoin();
		Bitcoin(Date date, float value);
		Bitcoin(const Bitcoin& other);
		~Bitcoin();

		Bitcoin&	operator=(const Bitcoin& other);

		static bool						initDb(void);
		static void						parseInfile(std::ifstream& f);
		static std::map<Date, float>&	getDb(void);

		void	searchDb(void) const;
		Date	getDate(void) const;
		float	getValue(void) const;
		void	setDate(Date date);
		void	setValue(float val);

};

std::ostream&	operator<<(std::ostream& out, const std::map<Date, float>& obj);

#endif