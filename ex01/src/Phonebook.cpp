#include "Phonebook.hpp"

Phonebook::Phonebook() :
	_contact()
	{};

void	Phonebook::save_contact(Contact *contact, int i) {
	contact->set_field("fname");
	contact->set_field("lname");
	contact->set_field("nname");
	contact->set_field("ph_number");
	contact->set_field("secret");
	this->_contact[i % 8] = *contact;
}

static std::string formatField(const std::string& str) {
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    else
        return (std::string(10 - str.length(), ' ') + str);
}

void	Phonebook::list_contacts(int size) {
	int	list_size;

	list_size = size;
	if (size >= 8)
		list_size = 8;
	std::cout << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < list_size; i++) {
		std::cout << std::setw(10) << i << "|"
			<< formatField(this->_contact[i].get_field("fname")) << "|"
			<< formatField(this->_contact[i].get_field("lname")) << "|"
			<< formatField(this->_contact[i].get_field("nname")) << std::endl;
	}
}

void	Phonebook::contact_info(int size) {
	std::string	user_input;
	int			i;

	list_contacts(size);
	while (true)
	{
		std::cout << "Enter the contact's index to display: ";
		std::getline(std::cin, user_input);
		if (user_input == ".")
			return ;
		try {
			i = std::stoi(user_input);
			if (i < 0 || i > size - 1) {
                std::cout << RED << "❌ Error: Out of range " << RES;
				std::cout << "(Press . to return to the menu)" << std::endl;
                continue;
			}
			break ;
		}
		catch (const std::invalid_argument& e) {
			std::cout << RED << "❌ Error: Invalid input " << RES ;
			std::cout << "(Press . to return to the menu)" << std::endl;
		}
	}
	std::cout << this->_contact[i].get_field("fname") << std::endl;
	std::cout << this->_contact[i].get_field("lname") << std::endl;
	std::cout << this->_contact[i].get_field("nname") << std::endl;
	std::cout << this->_contact[i].get_field("ph_number") << std::endl;
	std::cout << this->_contact[i].get_field("secret") << std::endl;
}
