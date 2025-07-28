#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

// std::string significa que es tipo string
class Contact
{
	public:
		std::string name;
		std::string last_name;
		std::string nickname;
		std::string phone;
		std::string secret;
	void display(void) // mira de entender
	{
		std::cout << name;
		std::cout << " : ";
		std::cout << phone << std::endl;
	}
};

class PhoneBook
{
	public:
	Contact Contacts[8];
	int	num;
};

#endif