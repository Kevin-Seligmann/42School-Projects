#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

static void showOptions(void){
	std::cout << std::endl;
	std::cout << "Write ADD to add a new contact" << std::endl;
	std::cout << "Write SEARCH to display a contact" << std::endl;
	std::cout << "Write EXIT to exit" << std::endl;
	std::cout << std::endl;
}

static void addContact(PhoneBook & phonebook){
	Contact contact;
	std::string answer;

	std::cout << "First name: ";
	std::getline(std::cin, answer);
	contact.setFirstName(answer);
	std::cout << "Last name: ";
	std::getline(std::cin, answer);
	contact.setLastName(answer);
	std::cout << "Nickname: ";
	std::getline(std::cin, answer);
	contact.setNickname(answer);
	std::cout << "Phone number: ";
	std::getline(std::cin, answer);
	contact.setPhoneNumber(answer);
	std::cout << "A deep secret: ";
	std::getline(std::cin, answer);
	contact.setSecret(answer);

	phonebook.addContact(contact);
}

static void searchContact(PhoneBook & phonebook){
	int i;

	phonebook.displayContacts();

	std::cout << "Input an index" << std::endl;
	std::cin >> i;
	if (std::cin.fail()){
		std::cerr << "Input error" << std::endl;
		std::cin.clear();
	} else {
		phonebook.displayContact(i);
	}
	std::cin.ignore(1000000, '\n');
}

int	main(void)
{
	PhoneBook phonebook;
	std::string answer;

	while (1){
		showOptions();
		std::getline(std::cin, answer);
		if (answer == "ADD")
			addContact(phonebook);
		else if (answer == "SEARCH")
			searchContact(phonebook);
		else if (answer == "EXIT"){
			break ;
		}
		else
			std::cout << "Wrong input, try again\n" << std::endl;
	}
}
