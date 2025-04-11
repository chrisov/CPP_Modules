#include "MyAwesomePhonebook.hpp"

int	main (void)
{
	std::string	input;
	Phonebook	book;
	Contact		contact;
	int			i;

	i = 0;
	while (1)
	{
		std::cout << "Input one of the following commands: (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, input);
		if (input == "ADD")
			book.save_contact(&contact, i++);
		else if (input == "SEARCH")
			book.contact_info(i);
		else if (input == "EXIT")
			break ;
		else
			std::cout << RED << "Invalid request!" << RES << std::endl;
		if (i < 8)
			i = 0;
	}
	return (0);
}