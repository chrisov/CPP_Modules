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

		
		class BTCException : std::exception {
			private:
				std::string	_msg;

			public:
				BTCException() = delete;
				BTCException(const std::string& msg);
				BTCException(const BTCException& other) = delete;
				~BTCException();

				BTCException&	operator=(const BTCException& other) = delete;

				const char*	what(void) const noexcept override;
		};
		
		//rest of the constructor? canonical
		class NegativeValueException : public BTCException {
			public:
				NegativeValueException() : BTCException("Not a positive value!") {}
		};

		class ExtremelyLargeValueException : public BTCException {
			public:
				ExtremelyLargeValueException() : BTCException("Too large of a value!") {}
		};
};

std::ostream&	operator<<(std::ostream& out, const std::map<Date, float>& obj);

#endif