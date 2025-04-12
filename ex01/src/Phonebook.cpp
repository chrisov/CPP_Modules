#include "Phonebook.hpp"

Phonebook::Phonebook() :
	_contact()
	{};

void	Phonebook::save_contact(Contact *contact, int i) {
	contact->set_field("first_name");
	contact->set_field("last_name");
	contact->set_field("nickname");
	contact->set_field("phone_number");
	contact->set_field("secret");
	this->_contact[i] = *contact;
}

static std::string formatField(const std::string& str) {
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    else
        return (std::string(10 - str.length(), ' ') + str);
}

void	Phonebook::list_contacts(int size) {
	std::cout << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << std::setw(10) << i << "|"
			<< formatField(this->_contact[i].get_field("first_name")) << "|"
			<< formatField(this->_contact[i].get_field("last_name")) << "|"
			<< formatField(this->_contact[i].get_field("nickname")) << std::endl;
	}
}

void	Phonebook::contact_info(int size) {
	std::string	input;
	int			i;

	list_contacts(size);
	while (true)
	{
		std::cout << "Enter the contact's index to display: ";
		std::getline(std::cin, input);
		if (input == ".")
			return ;
		try {
			i = std::stoi(input);
			if (i < 1 || i > size) {
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
	std::cout << this->_contact[i].get_field("first_name") << std::endl;
	std::cout << this->_contact[i].get_field("last_name") << std::endl;
	std::cout << this->_contact[i].get_field("nickname") << std::endl;
	std::cout << this->_contact[i].get_field("phone_number") << std::endl;
	std::cout << this->_contact[i].get_field("secret") << std::endl;
}
