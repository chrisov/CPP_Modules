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
		bool	operator>(const Date& other) const;

		void	setDate(char *date);
		int		getYear(void) const;
		int		getMonth(void) const;
		int		getDay(void) const;
		
		class DateException : public std::exception {
			private:
				std::string	_msg;
			
			public:
				DateException() = delete;
				DateException(const std::string& msg);
				DateException(const DateException& other) = delete;
				~DateException();

				DateException& operator=(const DateException& other) = delete;

				const char*	what(void) const noexcept override;
		};
		
		class DayOutOfRangeException : public DateException {
			public:
				DayOutOfRangeException() : DateException("Day out of range!") {}
		};

		class MonthOutOfRangeException : public DateException {
			public:
				MonthOutOfRangeException() : DateException("Month out of range!") {}
		};
};

std::ostream&	operator<<(std::ostream& out, const Date& obj);

#endif