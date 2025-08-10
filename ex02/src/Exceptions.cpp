#include "../inc/Exceptions.hpp"

/****************************************************
*					PMERGEME						*
****************************************************/

PmergeMeException::PmergeMeException(const std::string& msg) : _msg(msg) {};

PmergeMeException::~PmergeMeException() {}

const char*	PmergeMeException::what(void) const noexcept {
	return (_msg.c_str());
}

/****************************************************
*					NEGATIVENUMBER					*
****************************************************/

NegativeNumberException::NegativeNumberException() : PmergeMeException("Not a positive value!") {};

NegativeNumberException::~NegativeNumberException() {};

/****************************************************
*					DUPLICATENUMBER					*
****************************************************/

DuplicateNumberException::DuplicateNumberException() : PmergeMeException("Duplicate number!") {};

DuplicateNumberException::~DuplicateNumberException() {};

/****************************************************
*					UNITARYARRAY					*
****************************************************/

UnitaryArrayException::UnitaryArrayException() : PmergeMeException("Array too small!") {}

UnitaryArrayException::~UnitaryArrayException() {}
