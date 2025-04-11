
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

#define RED "\033[31m"
#define RES "\033[0m"

enum Action {
	FIRST_NAME = 1,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	SECRET
};

class Contact {

private:
	std::string	_firstname;
	std::string	_lastname;
	std::string	_nickname;
	std::string	_phonenumber;
	std::string	_secret;

public:
	Contact ();

	void		action_attribute_set(Action action, std::string value);
	void		set_field(const std::string case_input);
	std::string	get_field(const std::string case_input);
};

#endif