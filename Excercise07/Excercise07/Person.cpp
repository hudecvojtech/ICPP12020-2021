#include "Person.h"



Person::Person()
{
	_firstName = "";
	_lastName = "";

}

Person::Person(std::string firstName, std::string lastName, Address permanentResidence, Date dateOfBirth)
{
	_firstName = firstName;
	_lastName = lastName;
	_permanentResidence = permanentResidence;
	_dateOfBirth = dateOfBirth;
}

std::ostream& operator<<(std::ostream& out, const Person& person)
{
	out << person._firstName << " " << person._lastName << " " << person._permanentResidence << " " << person._dateOfBirth;
	return out;
}

std::istream& operator>>(std::istream& in, Person& person)
{
	in >> person._firstName;
	in >> person._lastName;
	in >> person._permanentResidence;
	in >> person._dateOfBirth;
	return in;
}
