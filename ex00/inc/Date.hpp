#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <exception>
#include "Colors.hpp"
#include "ParseUtils.hpp"

class Date : public std::exception{
	
	private:
		int	_year;
		int	_month;
		int	_day;

	public:
		Date();
		Date(int year, int month, int day);
		Date(const Date& other);
		~Date();

		Date&	operator=(const Date& obj);
		bool	operator<(const Date& other) const;

		void	setDate(char *date);
		int		getYear(void) const;
		int		getMonth(void) const;
		int		getDay(void) const;
		// Date&	getDate(void) const;
		
		class DayOutOfRangeException : std::exception {
			public:
				const char*	what(void) const noexcept override;
		};

		class MonthOutOfRangeException : std::exception {
			public:
				const char*	what(void) const noexcept override;
		};
};

std::ostream&	operator<<(std::ostream& out, const Date& obj);

#endif