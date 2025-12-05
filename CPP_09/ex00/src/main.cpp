#include "../inc/Bitcoin.hpp"

int main (int argc, const char **argv) {
	if (argc == 1)
		return (std::cerr << color("Error", RED) << ": File not provided!" << std::endl, 1);
	if (!Bitcoin::initDb())
		std::cerr << color("Error", RED) << ": Database not provided!" << std::endl;
	std::ifstream infile(argv[1]);
	if (!infile.is_open())
		return (std::cerr << color("Error", RED) << ": Could not open file!" << std::endl, 1);
	Bitcoin::parseInfile(infile);
	infile.close();
	return (0);
}
