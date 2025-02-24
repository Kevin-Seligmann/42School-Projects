#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

// Canonical
PhoneBook::PhoneBook(void){
	this->_contactsCount = 0;
}

PhoneBook::PhoneBook(PhoneBook const & cpy){
	*this = cpy;
}

PhoneBook::~PhoneBook(void)
{
}

PhoneBook & PhoneBook::operator=(PhoneBook const & src){
	int i = 0;
	int contactsCount = src._contactsCount;

	if (this != &src){
		while (i < contactsCount){
			this->_contacts[i] = src._contacts[i];
			i ++;
		}
		this->_contactsCount = contactsCount;
	}
	return *this;
}

void PhoneBook::addContact(Contact const & contact){
	int				i;

	if (this->_contactsCount < 8)
	{
		this->_contacts[this->_contactsCount] = contact;
		this->_contactsCount ++;
	}
	else {
		i = 0;
		while (i < 7){
			this->_contacts[i] = this->_contacts[i + 1];
			i ++;
		}
		this->_contacts[i] = contact;
	}
}

void PhoneBook::displayContact(int i){
	if (i < 1 || i > 8 || i > this->_contactsCount){
		std::cout << "The contact doesn't exist" << std::endl;
	} else {
		i --;
		std::cout << "First name: "<< this->_contacts[i].getFirstName() << std::endl;
		std::cout << "Last name: "<< this->_contacts[i].getLastName() << std::endl;
		std::cout << "Nickname: "<< this->_contacts[i].getNickname() << std::endl;
		std::cout << "Phone number: "<< this->_contacts[i].getPhoneNumber() << std::endl;
		std::cout << "Secret: "<< this->_contacts[i].getSecret() << std::endl;
	}
}

void PhoneBook::displayContacts(void){
	int i = 0;
	int	const width = 10;
	std::string str;

	while (i ++ < width * 3 + 4)
		std::cout << "-";
	i = 0;
	std::cout << std::endl;
	std::cout << "|";
	std::cout << std::setw(width) << "index" << "|";
	std::cout << std::setw(width) << "first name" << "|";
	std::cout << std::setw(width) << "last name" << "|" << std::endl;
	while (i ++ < width * 3 + 4)
		std::cout << "-";
	std::cout << std::endl;
	i = 0;
	while (i < this->_contactsCount){
		std::cout << "|";
		std::cout << std::setw(width) << i + 1 << "|";
		str = this->_contacts[i].getFirstName();
		if (str.length() > width)
			std::cout << str.substr(0, width - 1) << ".|";
		else
			std::cout << std::setw(width) << str << "|";
		str = this->_contacts[i].getLastName();
		if (str.length() > width)
			std::cout << str.substr(0, width - 1) << ".|" << std::endl;
		else
			std::cout << std::setw(width) << str << "|" << std::endl;
		i ++;
	}
	i = 0;
	while (i ++ < width * 3 + 4)
		std::cout << "-";
	std::cout << std::endl;
}
