#include "../inc/ScalarConverter.hpp"

static bool	validInt(const char *str) {
	while (*str) {
		if (*str != '-' && *str != '+' && (*str < 48 || *str > 57))
			return (false);
		str++;
	}
	return (true);
}

static bool	validDouble(const char *str) {
	if (!strcmp(str, "nan") || !strcmp(str, "inf")
		|| !strcmp(str, "+inf") || !strcmp(str, "-inf"))
		return (true);
	while (*str) {
		if (*str != '-' && *str != '+' && *str != '.'
			&& (*str < 48 || *str > 57))
			return (false);
		str++;
	}
	return (true);
}

static bool	validFloat(const char *str) {
	if (!strcmp(str, "nanf") || !strcmp(str, "inff")
		|| !strcmp(str, "+inff") || !strcmp(str, "-inff"))
		return (true);
	while (*str) {
		if (*str != '-' && *str != '+' && *str != '.' && *str != 'f'
			&&  (*str < 48 || *str > 57))
			return (false);
		str++;
	}
	return (true);
}

std::string	getType(const char *str) {
	if (validInt(str))
		return ("int");
	else if (validDouble(str))
		return ("double");
	else if (validFloat(str))
		return ("float");
	return ("Unknown parameter type");
}
