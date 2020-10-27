#ifndef TIME_H
#define TIME_H
#include "IComparable.h"
#include <string>


class Time : public IComparable {
private:
	int _hour;
	int _min;
	int _sec;

public:
	Time(int hour, int min, int sec);
	int CompareTo(IComparable* obj) const;
	std::string ToString() const;
};

#endif // !TIME_H

