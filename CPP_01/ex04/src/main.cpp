
#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char **argv) {
	std::string		line;
	size_t			i;

	if (argc != 4)
		return (std::cout << "Usage: " << argv[0] << " <inputfile> <target> <replacement>\n" << std::endl, 0);
	std::ifstream infile(argv[1]);
	std::ofstream outfile(std::string(argv[1]) + ".replace");
	if (!infile || !outfile)
		return (std::cout << "Error opening file!" << std::endl, 0);
	while (std::getline(infile, line)) {
		i = line.find(argv[2]);
		if (i == std::string::npos)
			outfile << line << std::endl;
		else {
			outfile << line.substr(0, i);
			outfile << argv[3];
			i += std::string(argv[2]).length();
			outfile << line.substr(i) << std::endl;
		}
	}
	infile.close();
	outfile.close();
	return (0);
}
