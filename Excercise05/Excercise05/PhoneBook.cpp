#include "PhoneBook.h"
#include "InputErrorException.h"
#include "NotExistException.h"

Model::PhoneBook::PhoneBook()
{
	_first = NULL;
	_last = NULL;
}

void Model::PhoneBook::addPerson(Entity::Person p)
{
	Element* e = new Element;
	e->p = p;
	e->next = NULL;

	if (_first == NULL) {
		_first = e;
		_last = e;
	}
	else {
		_last->next = e;
		_last = _last->next;
	}
}

std::string Model::PhoneBook::findPhone(std::string name) const
{
	if (name.empty())
		throw InputErrorException();

	Element* e;
	e = _first;
	while (e != NULL) {
		if (e->p.GetName() == name)
			return e->p.GetPhone();
		e = e->next;
	}

	throw NotExistException();
}

std::string Model::PhoneBook::findPhone(int id) const
{
	if (id < 0)
		throw InputErrorException();

	Element* e;
	e = _first;
	while (e != NULL) {
		if (e->p.GetId() == id)
			return e->p.GetPhone();
		e = e->next;
	}

	throw NotExistException();
}
