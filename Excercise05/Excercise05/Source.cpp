#include <iostream>
#include "PhoneBook.h"
#include "Person.h"
#include "InputErrorException.h"
#include "NotExistException.h"

int main(char** argv, int argc) {
	Model::PhoneBook phonebook;
	Entity::Person p;
	Entity::Person p2;
	p.SetId(1);
	p.SetName("asdf");
	p.SetPhone("1234");
	p2.SetId(2);
	p2.SetName("test2");
	p2.SetPhone("1234");
	phonebook.addPerson(p);
	phonebook.addPerson(p2);
	
	try {
		std::cout << phonebook.findPhone("test2a") << std::endl;
	}
	catch (NotExistException& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << phonebook.findPhone("") << std::endl;
	}
	catch (InputErrorException& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << phonebook.findPhone(-5) << std::endl;
	}
	catch (InputErrorException& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << phonebook.findPhone(1) << std::endl;
	}
	catch (InputErrorException& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << phonebook.findPhone("test2") << std::endl;
	}
	catch (InputErrorException& e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}