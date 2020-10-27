#include "Time.h"

Time::Time(int hour, int min, int sec)
{
	_hour = hour;
	_min = min;
	_sec = sec;
}

int Time::CompareTo(IComparable* obj) const {
	if (obj == nullptr)
		throw "Null object";

	Time* t = dynamic_cast<Time*>(obj);
	int result1 = _hour * 3600 + _min * 60 + _sec;
	int result2 = t->_hour * 3600 + t->_min * 60 + t->_sec;
	if (result1 == result2) return 0;
	if (result1 < result2) return -1;
	return 1;
}

std::string Time::ToString() const
{
	return std::to_string(_hour) + ':' + std::to_string(_min) + ':' + std::to_string(_sec);
}
