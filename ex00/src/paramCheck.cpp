#include "../inc/ScalarConverter.hpp"

static bool	validInt(char *str) {
	while (*str) {
		if (*str != '-' && *str != '+' && (*str < 48 || *str > 57))
			return (false);
		str++;
	}
	return (true);
}

static bool	validDouble(char *str) {
	while (*str) {
		if (*str != '-' && *str != '+' && *str != '.'
			&& (*str < 48 || *str > 57))
			return (false);
		str++;
	}
	return (true);
}

static bool	validFloat(char *str) {
	while (*str) {
		if (*str != '-' && *str != '+' && *str != '.' && *str != 'f'
			&&  (*str < 48 || *str > 57))
			return (false);
		str++;
	}
	return (true);
}

std::string	getType(char *str) {
	if (validInt(str))
		return ("int");
	if (validDouble(str))
		return ("double");
	if (validFloat(str))
		return ("float");
	return ("Unknown parameter type");
}
