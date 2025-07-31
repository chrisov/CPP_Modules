#include "../inc/easyfind.hpp"

const char* ElementNotFound::what(void) const noexcept {
	return ("Element not found!");
}
