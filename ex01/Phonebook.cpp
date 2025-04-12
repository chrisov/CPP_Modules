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

void	Phonebook::contact_info(int i) {
	std::string	input;

	list_contacts(i);
	std::cout << "Enter the contact's index to display: ";
	std::getline(std::cin, input);
	while (std::stoi(input) < 0 || std::stoi(input) > i)
	{
		std::cout << RED << "Invalid index!" << RES << std::endl;
		std::cout << "Enter the contact's index to display: ";
		std::getline(std::cin, input);
	}
	std::cout << this->_contact[std::stoi(input)].get_field("first_name") << std::endl;
	std::cout << this->_contact[std::stoi(input)].get_field("last_name") << std::endl;
	std::cout << this->_contact[std::stoi(input)].get_field("nickname") << std::endl;
	std::cout << this->_contact[std::stoi(input)].get_field("phone_number") << std::endl;
	std::cout << this->_contact[std::stoi(input)].get_field("secret") << std::endl;
}
