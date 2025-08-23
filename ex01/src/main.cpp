#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>

int	main (void)
{
	std::string	user_input;
	Phonebook	book;
	Contact		contact;
	int			cont_i;

	cont_i = 0;
	std::cout << "Welcome to the phonebook!" << std::endl;
	while (1)
	{
		std::cout << "Input one of the following commands (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, user_input);
		if (std::cin.eof())
		{
			std::cout << RED << "\nEOF detected, exiting program!" << RES << std::endl;
			break;
		}
		else if (user_input == "ADD")
			book.save_contact(&contact, cont_i++);
		else if (user_input == "SEARCH")
			book.contact_info(cont_i);
		else if (user_input == "EXIT")
			break ;
		else
			std::cout << RED << "Invalid request!" << RES << std::endl;
	}
	return (0);
}