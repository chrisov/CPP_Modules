#include "../inc/Exceptions.hpp"

/****************************************************
*					BTCEXCEPTION					*
****************************************************/

BTCException::BTCException(const std::string& msg) : _msg(msg) {}

BTCException::~BTCException() {}

const char*	BTCException::what(void) const noexcept {
	return (_msg.c_str());
}

/****************************************************
*					NEGATIVEVALUE					*
****************************************************/

NegativeValueException::NegativeValueException() : BTCException("Not a positive value!") {}

NegativeValueException::~NegativeValueException() {}

/****************************************************
*					EXTREMELYLARGE					*
****************************************************/

ExtremelyLargeValueException::ExtremelyLargeValueException() : BTCException("Too large of a value!") {}

ExtremelyLargeValueException::~ExtremelyLargeValueException() {}

/****************************************************
*					DATEEXCEPTION					*
****************************************************/

DateException::DateException(const std::string& msg) : _msg(msg) {}

DateException::~DateException() {}

const char*	DateException::what(void) const noexcept {
	return (_msg.c_str());
}

/****************************************************
*					DAYOUTOFRANGE					*
****************************************************/

DayOutOfRangeException::DayOutOfRangeException() : DateException("Day out of range!") {}

DayOutOfRangeException::~DayOutOfRangeException() {}

/****************************************************
*					MONTHOUTOFRANGE					*
****************************************************/

MonthOutOfRangeException::MonthOutOfRangeException() : DateException("Month out of range!") {}

MonthOutOfRangeException::~MonthOutOfRangeException() {}