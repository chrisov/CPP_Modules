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
		int		_value;
		
		static std::map<Date, double>	_db;

	public:
		Bitcoin() = delete;
		Bitcoin(Date date, int value);
		Bitcoin(const Bitcoin& other);
		~Bitcoin();

		Bitcoin&	operator=(const Bitcoin& other);

		static bool	initDb(void);
		static std::map<Date, double>&	getDb(void);

		Date&					getDate(void) const;
		int						getValue(void) const;

		class ValueOutOfRange : std::exception {
			public:
				const char*	what(void) const noexcept override;
		};
};

std::ostream&	operator<<(std::ostream& out, const std::map<Date, double>& obj);

#endif