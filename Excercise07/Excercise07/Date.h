#ifndef DATE_H
#define DATE_H
#include <iostream>

struct Date {
private:
	int _day;
	int _month;
	int _year;

public:
	Date();
	Date(int day, int month, int year);
	friend std::ostream& operator<< (std::ostream& out, const Date& date);
	friend std::istream& operator>> (std::istream& in, Date& date);
};



#endif // !DATE_H

