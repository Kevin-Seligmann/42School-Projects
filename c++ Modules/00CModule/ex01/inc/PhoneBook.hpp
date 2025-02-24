#ifndef PHONEBOOK_HPP
# define PHOPHONEBOOKP

# include "Contact.hpp"

class PhoneBook {

	public:
		PhoneBook(void);
		~PhoneBook(void);
		PhoneBook(PhoneBook const & cpy);
		PhoneBook & operator=(PhoneBook const & src);

		void addContact(Contact const & contact);
		void displayContacts(void);
		void displayContact(int i);

	private:
		Contact _contacts[8];
		int		_contactsCount;
};

#endif
