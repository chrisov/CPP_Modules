#include "../inc/Harl.hpp"

Harl::Harl() {}

void	Harl::debug(void) {
	std::cout << "[DEBUG]	I love extra bacon!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "[INFO]	Adding more bacon!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[WARNING]	That might be too much bacon!" << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ERROR]	This is unacceptable!" << std::endl;
}

void	Harl::complain(std::string level) {
	if (level == "DEBUG")
		debug();
	else if (level == "INFO")
		info();
	else if (level == "WARNING")
		warning();
	else if (level == "ERROR")
		error();
	else
		std::cout << "Not a complain.." << std::endl;
}