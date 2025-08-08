#include "Colors.hpp"
#include <algorithm>

/****************************************************
*					EXCEPTIONS						*
****************************************************/

ElementNotFoundException::ElementNotFoundException() {}

ElementNotFoundException::~ElementNotFoundException() {}

const char* ElementNotFoundException::what(void) const noexcept {
	return ("Element not found!");
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

template <typename T>
void	easyFind(T& cont, int val) {
	auto res = std::find(cont.begin(), cont.end(), val);
	if (res != cont.end()) {
		std::size_t idx = std::distance(cont.begin(), res);
		std::cout << color(std::to_string(val), YLW) << ": " << color("Found", GRN) << " at index: " << idx << std::endl;
	}
	else
		std::cout << color(std::to_string(val), YLW) << ": " << color("Not", RED) << " found!" << std::endl;
}

template <typename T>
void	printArray(T arr) {
	std::cout << "Array: {";
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it;
        if (std::next(it) != arr.end()) {
            std::cout << ", ";
        }
    }
	std::cout << '}' << std::endl;
}
