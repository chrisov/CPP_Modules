#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <iostream>
#include <exception>

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

class NegativeValueException : public BTCException {
	public:
		NegativeValueException();
		NegativeValueException(const NegativeValueException& other) = delete;
		~NegativeValueException();

		NegativeValueException&	operator=(NegativeValueException& other) = delete;
};

class ExtremelyLargeValueException : public BTCException {
	public:
		ExtremelyLargeValueException();
		ExtremelyLargeValueException(const ExtremelyLargeValueException& other) = delete;
		~ExtremelyLargeValueException();

		ExtremelyLargeValueException& operator=(const ExtremelyLargeValueException& other) = delete;
};

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
		DayOutOfRangeException();
		DayOutOfRangeException(const DayOutOfRangeException& other) = delete;
		~DayOutOfRangeException();

		DayOutOfRangeException& operator=(const DayOutOfRangeException& other) = delete;
};

class MonthOutOfRangeException : public DateException {
	public:
		MonthOutOfRangeException();
		MonthOutOfRangeException(const MonthOutOfRangeException& other) = delete;
		~MonthOutOfRangeException();

		MonthOutOfRangeException&	operator=(const MonthOutOfRangeException& other) = delete;
};

#endif