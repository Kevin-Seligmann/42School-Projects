#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {

public:
	Contact(void);
	~Contact(void);
	Contact(Contact const & cpy);
	Contact & operator=(Contact const & src);
	
	std::string const & getFirstName(void) const;
	std::string const & getLastName(void) const;
	std::string const & getNickname(void) const;
	std::string const & getSecret(void) const;
	std::string const & getPhoneNumber(void) const;

	void setFirstName(std::string const & s);
	void setLastName(std::string const & s);
	void setNickname(std::string const & s);
	void setSecret(std::string const & s);
	void setPhoneNumber(std::string const & s);

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string _secret;
	std::string _phoneNumber;

};

#endif
