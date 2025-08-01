#include "Colors.hpp"
#include <algorithm>

template <typename T>
void	easyfind(T& cont, int val) {
	auto res = std::find(cont.begin(), cont.end(), val);
	if (res != cont.end()) {
		std::size_t idx = std::distance(cont.begin(), res);
		std::cout << color(std::to_string(val), YLW) << ": " << color("Found", GRN) << " at index: " << idx << std::endl;
	}
	else
		std::cout << color(std::to_string(val), YLW) << ": " << color("Not", RED) << " found!" << std::endl;
}