#ifndef ICOMPARABLE_H
#define ICOMPARABLE_H
#include <string>

class IComparable {
public:
	virtual int CompareTo(IComparable* obj) const = 0;
	virtual std::string ToString() const;
	~IComparable() { };
};

#endif // !ICOMPARABLE_H

