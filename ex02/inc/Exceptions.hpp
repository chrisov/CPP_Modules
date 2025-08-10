#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <iostream>
#include <exception>

class PmergeMeException : public std::exception {

	private:
		std::string	_msg;

	public:
		PmergeMeException() = delete;
		PmergeMeException(const std::string& msg);
		PmergeMeException(const PmergeMeException& other) = delete;
		~PmergeMeException();

		PmergeMeException&	operator=(const PmergeMeException& other) = delete;

		const char*	what(void) const noexcept override;
};

class NegativeNumberException : public PmergeMeException {
	public:
		NegativeNumberException();
		NegativeNumberException(const NegativeNumberException& other) = delete;
		~NegativeNumberException();

		NegativeNumberException& operator=(const NegativeNumberException& other) = delete;
};

class DuplicateNumberException : public PmergeMeException {
	public:
		DuplicateNumberException();
		DuplicateNumberException(const DuplicateNumberException& other) = delete;
		~DuplicateNumberException();

		DuplicateNumberException& operator=(const DuplicateNumberException& other) = delete;
};

#endif
