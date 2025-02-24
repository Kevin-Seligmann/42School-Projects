#include "Contact.hpp"
#include <string>

// Canonical form
Contact::Contact(void)	
{
}

Contact::Contact(Contact const & cpy){
	*this = cpy;
}

Contact::~Contact(void){
}

Contact & Contact::operator=(Contact const & src){
	if (this != &src){
		this->_firstName = src._firstName;
		this->_lastName = src._lastName;
		this->_nickname = src._nickname;
		this->_phoneNumber = src._phoneNumber;
		this->_secret = src._secret;
	}
	return *this;
}

// Getters
std::string const & Contact::getFirstName(void) const{
	return this->_firstName;
}

std::string const & Contact::getLastName(void) const{
	return this->_lastName;
}

std::string const & Contact::getNickname(void) const{
	return this->_nickname;
}

std::string const & Contact::getPhoneNumber(void) const{
	return this->_phoneNumber;
}

std::string const & Contact::getSecret(void) const{
	return this->_secret;
}
	
// Setters
void Contact::setFirstName(std::string const & s){
	this->_firstName = s;
}

void Contact::setLastName(std::string const & s){
	this->_lastName = s;
}

void Contact::setNickname(std::string const & s){
	this->_nickname = s;
}

void Contact::setPhoneNumber(std::string const & s){
	this->_phoneNumber = s;
}

void Contact::setSecret(std::string const & s){
	this->_secret = s;
}	
