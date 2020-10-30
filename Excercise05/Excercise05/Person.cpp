#include "Person.h"

void Entity::Person::SetName(std::string name)
{
	this->name = name;
}

void Entity::Person::SetPhone(std::string phone)
{
	this->phone = phone;
}

void Entity::Person::SetId(int id)
{
	this->id = id;
}

std::string Entity::Person::GetName()
{
	return name;
}

std::string Entity::Person::GetPhone()
{
	return phone;
}

int Entity::Person::GetId()
{
	return id;
}
