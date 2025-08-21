#include "../inc/Bitcoin.hpp"

int main (int argc, const char **argv) {
	if (argc == 1)
		return (std::cerr << color("Error", RED) << ": File not provided!" << std::endl, 1);
	if (!Bitcoin::initDb())
		std::cerr << color("Error", RED) << ": Database not provided!" << std::endl;
	std::ifstream infile(argv[1]);
	if (infile.is_open())
		Bitcoin::parseInfile(infile);
	else
		std::cerr << color("Error", RED) << ": Could not open file!" << std::endl;
	infile.close();
	return (0);
}
