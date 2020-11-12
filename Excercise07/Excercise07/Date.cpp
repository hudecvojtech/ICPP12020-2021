#include "Date.h"

Date::Date()
{
	
}

Date::Date(int day, int month, int year)
{
	_day = day;
	_month = month;
	_year = year;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << date._day << " " << date._month << " " << date._year;
	return out;
}

std::istream& operator>>(std::istream& in, Date& date)
{
	in >> date._day;
	in >> date._month;
	in >> date._year;
	return in;
}
