#include "../../inc/Character.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

ICharacter::~ICharacter() {
	std::cout << "Character " << color("interface", YLW) << " was " << color("destroyed", RED) << "!" << std::endl;
}
