#ifndef PERSON_H
#define PERSON_H
#include <string>

namespace Entity {
	class Person {
		std::string name;
		std::string phone;
		int id;
	public:
		void SetName(std::string name);
		void SetPhone(std::string phone);
		void SetId(int id);
		std::string GetName();
		std::string GetPhone();
		int GetId();
	};
}

#endif // !PERSON_H

