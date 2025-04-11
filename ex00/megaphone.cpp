#include <iostream>

std::string	ft_toupper(std::string str)
{
	for (char& c : str)
		c = std::toupper(c);
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
			std::cout << ft_toupper(argv[i]);
		std::cout << std::endl;
	}
	return (0);
}
