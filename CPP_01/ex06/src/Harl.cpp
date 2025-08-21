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

void	Harl::complain(Level lvl) {

	switch (lvl) {
		case DEBUG:
			debug();
			info();
			warning();
			error();
			break;
		case INFO:
			info();
			warning();
			error();
			break;
		case WARNING:
			warning();
			error();
			break;
		case ERROR:
			error();
			break;
		default:
			std::cout << "Probably complaining about insignificant problems..." << std::endl;
	}
}
