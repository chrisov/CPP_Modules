
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <string>

class Phonebook {

private:
	Contact		_contact[8];

public:
	Phonebook();

	void	save_contact(Contact *contact, int i);
	void	list_contacts(int size);
	void	contact_info(int size);
};

#endif
