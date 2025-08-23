
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

#define RED "\033[31m"
#define RES "\033[0m"

class Contact {

	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phonenumber;
		std::string	_secret;

	public:
		Contact();

		void		set_field(const std::string case_input);
		std::string	get_field(const std::string case_input);
};

#endif