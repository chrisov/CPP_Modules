#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <iostream>
#include <exception>

class BTCException : public std::exception {
	private:
		std::string	_msg;

	public:
		BTCException() = default;
		BTCException(const std::string& msg);
		BTCException(const BTCException& other) = default;
		~BTCException();

		BTCException&	operator=(const BTCException& other) = default;

		const char*	what(void) const noexcept override;
};

class NegativeValueException : public BTCException {
	public:
		NegativeValueException();
		NegativeValueException(const NegativeValueException& other) = default;
		~NegativeValueException();

		NegativeValueException&	operator=(NegativeValueException& other) = default;
};

class ExtremelyLargeValueException : public BTCException {
	public:
		ExtremelyLargeValueException();
		ExtremelyLargeValueException(const ExtremelyLargeValueException& other) = default;
		~ExtremelyLargeValueException();

		ExtremelyLargeValueException& operator=(const ExtremelyLargeValueException& other) = default;
};

class DateException : public std::exception {
	private:
		std::string	_msg;
	
	public:
		DateException() = default;
		DateException(const std::string& msg);
		DateException(const DateException& other) = default;
		~DateException();

		DateException& operator=(const DateException& other) = default;

		const char*	what(void) const noexcept override;
};

class DayOutOfRangeException : public DateException {
	public:
		DayOutOfRangeException();
		DayOutOfRangeException(const DayOutOfRangeException& other) = default;
		~DayOutOfRangeException();

		DayOutOfRangeException& operator=(const DayOutOfRangeException& other) = default;
};

class MonthOutOfRangeException : public DateException {
	public:
		MonthOutOfRangeException();
		MonthOutOfRangeException(const MonthOutOfRangeException& other) = default;
		~MonthOutOfRangeException();

		MonthOutOfRangeException&	operator=(const MonthOutOfRangeException& other) = default;
};

#endif