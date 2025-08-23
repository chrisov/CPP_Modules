	#include "Contact.hpp"

Contact::Contact() :
	_firstname(""),
	_lastname(""),
	_nickname(""),
	_phonenumber(""),
	_secret("")
	{}

/**
 * @brief Request for user input, checks its validity and returns the result.
 */
static std::string	parse_input(const std::string case_input) {
	std::string	user_input;

	if (case_input == "fname")
		std::cout << "First name: ";
	else if (case_input == "lname")
		std::cout << "Last name: ";
	else if (case_input == "nname")
		std::cout << "Nickname: ";
	else if (case_input == "ph_number")
		std::cout << "Phone number: ";
	else
		std::cout << "Darkest secret: ";
	while (true)
	{
		std::getline(std::cin, user_input);
		if (std::cin.eof())
			return ("");
		if (user_input == "" || user_input.find_first_not_of(' ') == std::string::npos)
			std::cout << RED << "Invalid input!" << RES << std::endl;
		else
			break ;
	}
	return (user_input);
}

void	Contact::set_field(const std::string case_input) {
	std::string		user_input;

	user_input = parse_input(case_input);
	if (case_input == "fname")
		this->_firstname = user_input;
	else if (case_input == "lname")
		this->_lastname = user_input;
	else if (case_input == "nname")
		this->_nickname = user_input;
	else if (case_input == "ph_number")
		this->_phonenumber = user_input;
	else
		this->_secret = user_input;
}

std::string	Contact::get_field(const std::string case_input) {
	if (case_input == "fname")
		return (this->_firstname);
	else if (case_input == "lname")
		return (this->_lastname);
	else if (case_input == "nname")
		return (this->_nickname);
	else if (case_input == "ph_number")
		return (this->_phonenumber);
	else
		return (this->_secret);
}

