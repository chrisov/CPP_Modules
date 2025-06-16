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
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void (Harl::*functions[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*functions[i])();
			return;
		}
	}
	std::cout << "Probably complaining about insignificant problems..." << std::endl;
}