#ifndef PERSON_H
#define PERSON_H
#include "Address.h"
#include "Date.h"
#include <iostream>

struct Person {
private:
	std::string _firstName;
	std::string _lastName;
	Address _permanentResidence;
	Date _dateOfBirth;

public:
	Person();
	Person(std::string firstName, std::string lastName, Address permanentResidence, Date dateOfBirth);
	friend std::ostream& operator<< (std::ostream& out, const Person& person);
	friend std::istream& operator>> (std::istream& in, Person& person);
};

#endif // !PERSON_H
