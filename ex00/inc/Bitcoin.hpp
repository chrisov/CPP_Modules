#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <iostream>
#include <map>
#include <fstream>
#include "Colors.hpp"
#include "Date.hpp"
#include "ParseUtils.hpp"

class Bitcoin {

	private:
		Date	_date;
		double	_value;
		
		static std::map<Date, double>	_db;

	public:
		Bitcoin();
		Bitcoin(Date date, double value);
		Bitcoin(const Bitcoin& other);
		~Bitcoin();

		Bitcoin&	operator=(const Bitcoin& other);

		static bool						initDb(void);
		static void						parseInfile(std::ifstream& f);
		static std::map<Date, double>&	getDb(void);

		void	searchDb(void) const;
		Date	getDate(void) const;
		double	getValue(void) const;
		void	setDate(Date date);
		void	setValue(double val);

		class NegativeValueException : std::exception {
			public:
				const char*	what(void) const noexcept override;
		};

		class ExtremelyLargeValueException : std::exception {
			public:
				const char*	what(void) const noexcept override;
		};
};

std::ostream&	operator<<(std::ostream& out, const std::map<Date, double>& obj);

#endif