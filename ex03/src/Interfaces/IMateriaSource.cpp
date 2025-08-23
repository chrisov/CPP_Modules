#include "../../inc/Interfaces/IMateriaSource.hpp"

IMateriaSource::~IMateriaSource() {
	std::cout << "MateriaSource " << color("interface", YLW) << " was " << color("destroyed", RED) << "!" << std::endl;
}
