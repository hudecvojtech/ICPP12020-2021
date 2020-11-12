#include "Address.h"

Address::Address()
{
	
}

Address::Address(std::string street, std::string city, int zip)
{
	_street = street;
	_city = city;
	_zip = zip;
}

std::ostream& operator<<(std::ostream& out, const Address& address)
{
	out << address._street << " " << address._city << " " << address._zip;
	return out;
}

std::istream& operator>>(std::istream& in, Address& address)
{
	in >> address._street;
	in >> address._city;
	in >> address._zip;
	return in;
}
