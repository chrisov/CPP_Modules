#include "Contact.hpp"

Contact::Contact() :
	_firstname(""),
	_lastname(""),
	_nickname(""),
	_phonenumber(""),
	_secret("")
	{}

static Action parse_action(const std::string input) {
	if (input == "first_name")
		return FIRST_NAME;
	else if (input == "last_name")
		return LAST_NAME;
	else if (input == "nickname")
		return NICKNAME;
	else if (input == "phone_number")
		return PHONE_NUMBER;
	return SECRET;
}

static void	action_input(Action action) {
	switch (action) {
		case (FIRST_NAME):
			std::cout << "First name: ";
			break;
		case (LAST_NAME):
			std::cout << "Last name: ";
			break;
		case (NICKNAME):
			std::cout << "Nickname: ";
			break;
		case (PHONE_NUMBER):
			std::cout << "Phone number: ";
			break;
		case (SECRET):
			std::cout << "Darkest secret: ";
			break;
	}
}

void	Contact::action_attribute_set(Action action, std::string value) {
	switch (action) {
		case (FIRST_NAME):
			this->_firstname = value;
			break;
		case (LAST_NAME):
			this->_lastname = value;
			break;
		case (NICKNAME):
			this->_nickname = value;
			break;
		case (PHONE_NUMBER):
			this->_phonenumber = value;
			break;
		case (SECRET):
			this->_secret = value;
			break;
	}
}

void	Contact::set_field(const std::string case_input) {
	std::string	input;
	Action		action;

	action = parse_action(case_input);
	action_input(action);
	std::getline(std::cin, input);
	while (input == "")
	{
		if (input == "" || input.find_first_not_of(' ') == std::string::npos) {
			std::cout << RED << "Invalid input!" << RES << std::endl;
		}		
		action = parse_action(case_input);
		action_input(action);
		std::getline(std::cin, input);
	}
	action_attribute_set(action, input);
}

std::string	Contact::get_field(const std::string case_input) {
	Action	action;

	action = parse_action(case_input);
	switch (action) {
		case (FIRST_NAME):
			return (this->_firstname);
		case (LAST_NAME):
			return (this->_lastname);
		case (NICKNAME):
			return (this->_nickname);
		case (PHONE_NUMBER):
			return (this->_phonenumber);
		default:
			return (this->_secret);
	}
}

