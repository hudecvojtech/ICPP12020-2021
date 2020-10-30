#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Person.h"
#include <string>

namespace Model {
	class PhoneBook {
		struct Element {
			Entity::Person p;
			Element* next = NULL;
		};

		Element* _first;
		Element* _last;
	public:
		PhoneBook();
		void addPerson(Entity::Person p);
		std::string findPhone(std::string name) const;
		std::string findPhone(int id) const;
	};
}

#endif // !PHONEBOOK_H

